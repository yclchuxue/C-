/**********************
 * 使用map储存名字
 * *******************/
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

                                    //传入要以引用，不然没有修改main函数中的值
void get_family(map<string, vector<string>> &families, string na)
{
    if(families.find(na) == families.end())
        families[na] = vector<string>();
}

void get_child(map<string, vector<string>> &families, string na, string named)
{      
    //vector中没有find，所以要使用泛型find
    if(find(families[na].begin(), families[na].end(), named) == families[na].end())
        families[na].push_back(named);
}

int main()
{
    map<string, vector<string>> families;

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