/********************
 * 测试for_each算法
 * *****************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};

    auto lam = [](const int &val){cout << val << "  ";};

    for_each(nums.begin(), nums.end(), lam);

    cout << endl;

    return 0;
}