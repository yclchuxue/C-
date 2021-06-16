#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void )
{
    int i,tao = 1,n;
    cin >> n;                             //输入n
    for(i = 0;i<n;i++)
    {
        tao = tao*2+1;
    }
    cout << "tao = "<<tao<<endl;
    system("pause");
    return 0;
}
