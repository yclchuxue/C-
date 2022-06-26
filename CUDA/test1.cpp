#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/epoll.h>
#include <iostream>

#define OPEN_MAX 1024

struct node{
    void *ptr;
};

using namespace std;

int main()
{
	int cfd, lfd, sfd, ret, n, i, maxi, efd, nready;
	struct sockaddr_in caddr, saddr;
	char buf[BUFSIZ], str[INET_ADDRSTRLEN];           //缓存区
    struct node data;
    
	socklen_t clen;

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(9997);               //端口号9998
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);      //TCP

	lfd = socket(AF_INET, SOCK_STREAM, 0);            //创建套接字
	bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));    //绑定端口
	listen(lfd, 128);                //设置监听套接字

    struct epoll_event tep, ep[OPEN_MAX];   //定义描述符和响应队列

    efd = epoll_create(OPEN_MAX);   

    tep.events = EPOLLIN;      
    tep.data.fd = lfd;

    ret = epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &tep);     //将监听套接字加入等待队列

    while(1)
    {
        nready = epoll_wait(efd, ep, OPEN_MAX, -1);     //等待就绪套接字，将就绪套接字放入响应队列，返回响应套接字的个数
        for(i = 0; i < nready; i++)
        {
            if(!ep[i].events & EPOLLIN)     //该套接字描述符不可读
                continue;
            if(ep[i].data.fd == lfd)          //监听套接字有响应，有新的套接字要连接服务器
            {
                clen = sizeof(caddr);
                cfd = accept(lfd, (struct sockaddr *)&caddr, &clen);        //连接套接字

                printf("connection--port:%d\tip:%s\n", ntohs(caddr.sin_port), inet_ntop(AF_INET, &caddr.sin_addr.s_addr, str, sizeof(str)));

                tep.data.fd = cfd;
                tep.events = EPOLLIN;
                ret = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &tep);      //将新套接字加入等待队列
            }
            else
            {
                sfd = ep[i].data.fd;
                n = read(sfd, &data, sizeof(struct node));         //读取套接字内容
                if(n == 0)         //客户端关闭
                {
                    ret = epoll_ctl(efd, EPOLL_CTL_DEL, sfd, NULL);    //将套接字sfd从等待队列中删除
                    close(sfd);        //关闭该套接字
                }
                else
                {
                    cout << "AAAAAAA0 " << endl;

                    cout << data.ptr << endl;
                }
            }
        }
    }
    close(lfd);
    return 0;
}


