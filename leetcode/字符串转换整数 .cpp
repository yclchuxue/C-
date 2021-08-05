/******************************
 * 字符串转换整数 (atoi)--8
 * ***************************/
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>  //INT_MIN和INT_MAX的头文件
#include <algorithm>
using namespace std;

#define INT_MIN = -2147483648
#define INT_MAX =  2147483647

//方法1----暴力
class Solution {
public:
    int myAtoi(string s)
    {
        int n = s.length(), sign = 1, m, ice = 0;
        int max = INT_MAX;
        long num = 0;
        for(int i = 0; i < n; ++i)
        {
            m = s[i] - '0';
            if(s[i] == '-')
            {
                if(ice == 1)
                {
                    break;
                }
                ice = 1;
                sign = -1;
            }
            else if(s[i] == '+')
            {
                if(ice == 1)
                {
                    break;
                }
                ice = 1;
                sign = 1;
            }
            else if(s[i] == ' ')
            {
                if(ice == 1)
                {
                    break;
                }
                continue;
            }
            else if(m <= 9 && m >= 0)
            {
                ice = 1;
                if((num*10 +m) > max)
                {
                    if(sign == -1)
                        return INT_MIN;
                    else
                        return INT_MAX;    
                }
                num = num*10 + m;
            }
            else
            {
                return num*sign;
            }
        }
        return num*sign;
    }
};

int main()
{
    string s = "   51236 5115va";
    Solution P;

    int ret = P.myAtoi(s);

    cout << ret << endl;

    return 0;
}