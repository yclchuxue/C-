/********************
 * 使用pair储存成绩
 * *****************/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void get_value(vector<pair<string, int>> &values, string name, int val)
{
    //有三种方法
    values.push_back(make_pair(name, val));
    //values.push_back(pair<string, int>(name, val));
    //values.push_back({name,val});
}

int main()
{
    vector<pair<string, int>> values;

    string name;
    int val;
    while(cin >> name >> val)
        get_value(values, name, val);
    
    for(auto val : values)
    {
        cout << val.first << ": " << val.second << endl;
    }

    return 0;
}