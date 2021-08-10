/**************************************
 * 测试部分算法组合，
 * ***********************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void emlimDups(vector<string> strs)     //去重
{
    sort(strs.begin(), strs.end());

    auto iter = unique(strs.begin(), strs.end());

    strs.erase(iter, strs.end());
}

void biggies(vector<string> &strs, vector<string>::size_type size)
{
    emlimDups(strs);

    auto lam_1 = [](const string &a, const string &b){return a.size() < b.size();};

    stable_sort(strs.begin(), strs.end(), lam_1);                     //将strs.begin()到strs.end()中的元素依次带入lam_1中

    auto lam_2 = [size](const string &a){return a.size() >= size;};

    auto iter = find_if(strs.begin(), strs.end(), lam_2);          //将strs.begin()到strs.end()中的元素依次带入lam_2中,直到返回值满足

    auto count = strs.end() - iter;

    cout << "大于" << size << "的个数为：" << count << endl;

    auto lam_3 = [](const string &s){cout << s << " ";};

    for_each(iter, strs.end(), lam_3);          //将iter到strs.end()中的元素依次带入lam_3中

    cout << endl;
}

int main()
{
    vector<string> strs = {"adb", "adiygvba", "acc", "aoudg", "add"};

    biggies(strs, 4);

    return 0;
}