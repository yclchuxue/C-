/************************************
 * forward_list 单向链表的特殊操作
 * *********************************/
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> list = {1,2,3,4,5,6,7,8,9,10,11};
    auto prev = list.before_begin();                   //获取首元素之前位置
    auto next = list.begin();                          //获取首元素位置

    while(next != list.end())
    {
        if(*next&1)
        {
            next = list.erase_after(prev);              //删除prev下一个位置的元素
        }
        else
        {
            prev = next;
            ++next;
        }
    }
    for(auto &i : list)
    {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}