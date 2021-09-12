/**********************************
 * leetcode-------字符串相乘----42
 * *******************************/
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int m = num1.size(), n = num2.size();
        string ret(m+n, '0');
        if(m ==0 || n == 0) return "0";
        for(int i = m-1;i >= 0; --i)
        {
            for(int j = n-1;j >= 0; --j)
            {
                int num = (num1[i] - '0') * (num2[j] - '0');
                num += ret[i+j+1] - '0';
                ret[i+j+1] = num%10 + 48;
                if(num >= 10) ret[i+j] = ret[i+j] - '0' + num/10 + 48; 
            }
        }
        int index=0;
        while(index<m+n-1 && ret[index]=='0') ++index;
        return ret.substr(index);
        return ret;
    }
};

int main()
{
    string num1 = "23", num2 = "16";
    Solution S;
    string ret = S.multiply(num1, num2);

    cout << ret << endl;

    return 0;
}