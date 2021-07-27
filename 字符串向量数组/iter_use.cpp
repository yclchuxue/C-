/************************************
 * 迭代器的使用
 * *********************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int val;
    vector<int> values;

    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        values.push_back(val);
    }

    for(auto it = values.begin(); it != values.end(); it++)
    {//输入1 2 3 4 5 6 7 8 9
        if(*it == 5)
        {
            cout << *it << endl;
            it += 2;       //相当于索引加2
            cout << *it << endl;
            it -= 4;       //相当于索引减2
            cout << *it << endl;
            //it = it2;    错误，vector迭代器没有 "=" 操作
            break;
        }
    }

    return 0;
}