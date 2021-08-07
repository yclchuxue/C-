/***************************
 * 测试fill和fill_n算法
 * ************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6,7};
    auto iter = nums.begin();
    while (iter != nums.end())
    {
        cout << *iter << "\t";
        ++iter;
    }
    cout << endl;

    fill(nums.begin(), nums.end(), 0);
    iter = nums.begin();
    while (iter != nums.end())
    {
        cout << *iter << "\t";
        ++iter;
    }
    cout << endl;

    fill_n(nums.begin(), nums.size()-2, 5);
    iter = nums.begin();
    while (iter != nums.end())
    {
        cout << *iter << "\t";
        ++iter;
    }
    cout << endl;

    return 0;
}