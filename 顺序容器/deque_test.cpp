/**************************************************
 * deque容器，双端队列，支持随机访问，支持首尾插入删除很快
 * ***********************************************/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<string> sdeq;
    string str;
    while(cin >> str)
    {
        if(str == "-1")
        {
            break;
        }
        sdeq.push_back(str);
    }
    for(auto beg = sdeq.begin(); beg != sdeq.end(); ++beg)
    {
        cout << *beg << "\t";
    }
    cout << endl;

    return 0;
}