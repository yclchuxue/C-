/******************************
 * accumulate操作
 * ***************************/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    cout << sum << endl;

    vector<string> strs = {"hello", " ", "world", "!"};
    //string str = accumulate(strs.begin(), strs.end(), "");   //”“不支持'+'
    string str = accumulate(strs.cbegin(), strs.cend(), string(""));
    cout << str << endl;

    return 0;
}