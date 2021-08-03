/*******************************
 * Excel 表列序号 171
 * *****************************/
 #include <iostream>
 #include <string.h>
 #include <vector>
 using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int ret = 0;
        for(char c : columnTitle)
        {
            ret = ret * 26 + (c - 'A' + 1);
        }
        return ret;
    }
};

int main()
{
    Solution P;
    string str = "AB";
    int ret = P.titleToNumber(str);
    cout << ret << endl;

    return 0;
}