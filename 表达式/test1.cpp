#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int i = 0;
    string str_1, str_2;
    while(cin >> str_1) //输入-1或EOF推出循环
    {
        if(str_1 == "-1")
        {
            break;
        }
        if(i == 0)
        {
            i = 1;
            str_2 = str_1;
        }
        else
        {
            if(str_1 == str_2)
            {
                i = 2;
                break;
            }
            else
            {
                str_2 = str_1;
            }
        } 
    }
    if(i == 2)
    {
        cout << "double string :" << str_1 << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    
}