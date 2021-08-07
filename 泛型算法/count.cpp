/***********************************
 * count函数的使用
 * ********************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//10.1
int main_1()
{
    vector<int> nums;
    int val;
    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        nums.push_back(val);
    }
    cout << count(nums.cbegin(), nums.cend(), 5) << endl;

    return 0;
}

//10.2
int main()
{
    vector<string>  strs;
    string str;
    while (cin >> str)
    {
        if(str == "-1")
        {
            break;
        }
        strs.push_back(str);
    }
    cout << count(strs.cbegin(), strs.cend(),"abc") << endl;

    return 0;
}