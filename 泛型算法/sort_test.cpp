/*****************************************
 * 测试算法sort和stable_sort
 * **************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> strs)     //去重
{
    sort(strs.begin(), strs.end());

    auto iter = unique(strs.begin(), strs.end());

    strs.erase(iter, strs.end());
}

int main()
{
    vector<string> strs = {"asbj", "bnd", "aiuwe", "jabcd", "ladnc", "abd"};

    //sort(strs.begin(), strs.end(), isShorter);       //按string长度的升序排序

    //sort(strs.begin(), strs.end());                  //按字典序排序

    stable_sort(strs.begin(), strs.end(), isShorter);  //按string长度的升序排序，并维持相等元素的原有顺序

    for(auto str : strs)
    {
        cout << str << "\t";
    }
    cout << endl;


    return 0;
}