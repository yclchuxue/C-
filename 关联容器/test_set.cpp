/******************
 * 使用set(和map)储存名字
 * ***************/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

                                    //传入要以引用，不然没有修改main函数中的值
void get_family(map<string, set<string>> &families, string na)
{
    if(families.find(na) == families.end())
        families[na] = set<string>();
}

void get_child(map<string, set<string>> &families, string na, string named)
{      
    families[na].insert(named); //自动去重
}

int main()
{
    map<string, set<string>> families;

    string na, named;
    while(cin >> na >> named)     //输入姓名时，姓和名以空格隔开
    {
        get_family(families, na);
        get_child(families, na, named);
    }

    for(auto fa : families)
    {
        cout << fa.first << "家： ";
        for(auto named : fa.second)
        {
            cout << named << "\t";
        }
        cout << endl;
    }

    return 0;
}