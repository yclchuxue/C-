#include <iostream>
#include <sched.h>
#include <vector>
#include <unistd.h>

using namespace std;

//管道通信

int main(){
    int fd1[2], fd2[2], fd3[3];
    int buf[100];

    pid_t pid, pid2, pid3;
    int ret = pipe(fd1);
    if(ret < 0){
        cout << "create pip1 error" << endl;
        return 0;
    }

    ret = pipe(fd2);
    if(ret < 0){
        cout << "create pip2 error" << endl;
        return 0;
    }

    ret = pipe(fd3);
    if(ret < 0){
        cout << "create pip3 error" << endl;
        return 0;
    }
    
    // createconsumer(1);

    for(int i = 0; i < 3; ++i){
        pid = fork();
        if(pid < 0){
            cout << "create consumer" << i + 1 << " error" << endl;
            return 0;
        }
        if(pid == 0){
            switch (i) {
                case 0:
                    close(fd1[1]);
                    while(1){
                        read(fd1[0], buf, sizeof(buf));

                        if(buf[0] == -1) break;

                        cout << "consumer1 read " << buf[0] << endl;
                    }
                    break;
                case 1:
                    close(fd2[1]);
                    while(1){
                        read(fd2[0], buf, sizeof(buf));

                        if(buf[0] == -1) break;

                        cout << "consumer2 read " << buf[0] << endl;
                    }
                    break;
                case 2:
                    close(fd3[1]);
                    while(1){
                        read(fd3[0], buf, sizeof(buf));

                        if(buf[0] == -1) break;

                        cout << "consumer3 read " << buf[0] << endl;
                    }
                    break;
            }
            break;
        }
    }

    if(pid > 0){
        //主进程作为producer
        int nums[] = {8, 9, 4, 1, 2, 6, -1};

        close(fd1[0]);
        close(fd2[0]);
        close(fd3[0]);

        for(int i = 0; i < 7; i++){
            buf[0] = nums[i];
            write(fd1[1], buf, sizeof(buf));
            write(fd2[1], buf, sizeof(buf));
            write(fd3[1], buf, sizeof(buf));
        }
    }
    return 0;

}