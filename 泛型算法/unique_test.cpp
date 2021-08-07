/***********************************
 * 测试unique算法
 * ********************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> strs = {"the", "quick", "read", "fox", "jumps", "over", "the", "slow", "read", "turtle"};

    sort(strs.begin(), strs.end());                //排序

    for(auto str : strs)
    {
        cout << str << "\t";
    }
    cout << strs.size() << endl;

    auto it = unique(strs.begin(), strs.end());    //将相邻的相同的放到后面，返回一个指
                                                   //向第一个被放到后面的元素的迭代器

    for(auto str : strs)
    {
        cout << str << "\t";
    }
    cout << strs.size() << endl;

    strs.erase(it, strs.end());                    //删除重复元素
 
    for(auto str : strs)
    {
        cout << str << "\t";
    }
    cout << strs.size() << endl;

    return 0;
}