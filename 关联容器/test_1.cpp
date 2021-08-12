/****************************
 * 储存姓 名和生日
 * 使用map，set，pair
 * *************************/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void get_family(map<string, set<pair<string, string>>> &families, string na)
{
    if(families.find(na) == families.end())
        families[na] = set<pair<string,string>>();
}

void get_child(map<string, set<pair<string, string>>> &families, string na, string named, string birthday)
{
    //set容器使用insert添加元素
    families[na].insert(make_pair(named, birthday));
}

int main()
{
    map<string, set<pair<string, string>>> families;

    string na, named, birthday;
    while(cin >> na >> named >> birthday)      //输入时姓，名，生日以空格隔开
    {
        get_family(families, na);
        get_child(families,  na, named, birthday);
    }

    for(auto nam : families)
    {
        cout << nam.first << "家 ：" << endl;
        for(auto val : nam.second)
        {
            cout <<  "\t名：" << val.first << "\t生日：" << val.second << endl; 
        }
    }

    return 0;
}