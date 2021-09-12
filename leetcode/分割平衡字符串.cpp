/***********************************
 * leetcode---分割平衡字符串---1221
 * ********************************/
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int num = 0, l = 0, r = 0, ret = 0;
        for(auto ch : s)
        {
            if(ch == 'L') ++l;
            if(ch == 'R') ++r;
            if(l  ==  r )
            {
                ++ret;
            }
        }
        return ret;
    }
};

int main()
{
    string strs = "RLRRLLLRRL";
    Solution S;
    int ret = S.balancedStringSplit(strs);
    
    cout << ret << endl;

    return 0;   
}