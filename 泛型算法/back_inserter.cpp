/************************
 * 测试back_inserter算法
 * *********************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    vector<int> nums = {0,1,2,3,4,5,6};
    auto iter = back_inserter(nums);
    *iter = 7;
    *iter = 8;
    auto it = nums.begin();
    while(it != nums.end()) 
    {
        cout << *it << "\t";   //输出到8
        ++it;
    }
    cout << endl;

    fill_n(iter, 5, 0);        //新加入5个值为0的元素
    it = nums.begin();
    while(it != nums.end()) 
    {
        cout << *it << "\t";   
        ++it;
    }
    cout << endl;

    return 0;
}