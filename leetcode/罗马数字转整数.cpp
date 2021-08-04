/***********************************
 * 罗马数字转整数--------13
 * ********************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//方法1-------暴力
class Solution {
public:
    int romanToInt(string s) 
    {
        int num = 0,n = s.length();
        for(int i = 0; i < n; ++i) 
        {
            if(s[i] == 'I')
            {
                if(i+1 < n && s[i+1] == 'I')
                {
                    if(s[i+2] == 'I' && i+2 < n)
                    {
                        num = num + 3;
                        i = i + 2;
                    }
                    else
                    {
                        i = i + 1;
                        num = num + 2;
                    }
                }
                else if(s[i+1] == 'V' && i+1 < n)
                {
                    num = num + 5-1;
                    i = i + 1;
                }
                else if(s[i+1] == 'X' && i+1 < n)
                {
                    i = i + 1;
                    num = num + 10-1;
                }
                else
                {
                    num = num + 1;
                }
            }
            else if(s[i] == 'X')
            {
                if(s[i+1] == 'L' && i+1 < n)
                {
                    num = num + 50 - 10;
                    i = i + 1;
                }
                else if(s[i+1] == 'C' && i+1 < n)
                {
                    num = num + 100 - 10;
                    i = i + 1;
                }
                else
                {
                    num = num + 10;
                }
            }
            else if(s[i] == 'C')
            {
                if(s[i+1] == 'D' && i+1 < n)
                {
                    num = num + 500 - 100;
                    i = i + 1;
                }
                else if(s[i+1] == 'M' && i+1 < n)
                {
                    num = num + 1000 - 100;
                    i = i + 1;
                }
                else
                {
                    num = num + 100;
                }
            }
            else if(s[i] == 'V')
            {
                num = num + 5;
            }
            else if(s[i] == 'X')
            {
                num = num + 10;
            }
            else if(s[i] == 'L')
            {
                num = num + 50;
            }
            else if(s[i] == 'C')
            {
                num = num + 100;
            }
            else if(s[i] == 'D')
            {
                num = num + 500;
            }
            else if(s[i] == 'M')
            {
                num = num + 1000;
            }
        }
        return num;
    }
};

int main()
{
    string s = "MCMXCIV";
    Solution P;

    int ret = P.romanToInt(s);

    cout << ret << endl;

    return 0;
}