#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> //atoi()
#include <iostream>
#include "cuda_runtime.h"

using namespace std;

struct node
{
    cudaIpcMemHandle_t ptr;
};

int main(int argc, char *argv[])
{
    //检查命令行参数是否匹配
    if (argc != 3)
    {
        printf("请传递要连接的服务器的ip和端口号");
        return -1;
    }

    int port = atoi(argv[2]);        //从命令行获取端口号
    if (port < 1025 || port > 65535) // 0~1024一般给系统使用，一共可以分配到65535
    {
        printf("端口号范围应为1025~65535");
        return -1;
    }

    // 1 创建tcp通信socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("socket failed!\n");
    }

    // 2 连接服务器
    struct sockaddr_in server_addr = {0};                                               //服务器的地址信息
    server_addr.sin_family = AF_INET;                                                   // IPv4协议
    server_addr.sin_port = htons(port);                                                 //服务器端口号
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);                                   //设置服务器IP
    int ret = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)); //连接服务器
    if (ret == -1)
    {
        perror("connect failed!\n");
    }
    else
    {
        printf("connect server successful!\n");
    }

    //要监视的描述符集合
    fd_set fds;

    // 3 send msg
    while (1)
    {
        FD_ZERO(&fds); //清空文件描述符集合

        FD_SET(0, &fds);

        FD_SET(socket_fd, &fds); //把网络通信文件描述符加入到集合中

        ret = select(socket_fd + 1, &fds, NULL, NULL, NULL);
        if (ret < 0) //错误
        {
            perror("select fail:");
            return -1;
        }
        else if (ret > 0) //有活跃的
        {
            //判断是否 标准输入设备活跃 假设是则发送数据
            if (FD_ISSET(0, &fds))
            {

                int *x, y;
                struct node data;
                scanf("%d", &y);

                auto status = cudaMalloc(&x, sizeof(int));
                if (status != cudaSuccess)
                {
                    fprintf(stderr, "cudaMalloc failed!");
                    cout << status << endl;
                }

                cudaIpcMemHandle_t p1;

                status = cudaMemcpy(x, &y, sizeof(int), cudaMemcpyHostToDevice);
                if (status != cudaSuccess)
                {
                    fprintf(stderr, "cudaMemcpy1 failed!");
                    cout << status << endl;
                }

                status = cudaIpcGetMemHandle(&p1, (void *)x);
                if (status != cudaSuccess)
                {
                    fprintf(stderr, "cudaIpcGetMemHandle failed!");
                    cout << status << endl;
                }

                data.ptr = p1;

                write(socket_fd, &data, sizeof(struct node));
                sleep(3);

                int z;
                status = cudaMemcpy(&z, x, sizeof(int), cudaMemcpyDeviceToHost);
                if (status != cudaSuccess)
                {
                    fprintf(stderr, "cudaMemcpy1 failed!");
                    cout << status << endl;
                }
                cout << "z = " << z << endl;
                cudaFree((void *)x);
            }
        }
    }

    // 4 关闭通信socket
    close(socket_fd);

    return 0;
}
