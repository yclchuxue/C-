#include <iostream>
#include <list>
using namespace std;
int main()
{
    //创建并初始化 2 个 list 容器
    list<int> mylist1{ 1,2,3,4 }, mylist2{10,20,30};
    list<int>::iterator it = ++mylist1.begin(); //指向 mylist1 容器中的元素 2
   
    //调用第一种语法格式
    // mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                 // mylist2:
                                 // it 迭代器仍然指向元素 2，只不过容器变为了 mylist1

    //调用第二种语法格式，将 it 指向的元素 2 移动到 mylist2.begin() 位置处
    // mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1: 1 10 20 30 3 4
                                                    // mylist2: 2
                                                    // it 仍然指向元素 2
   
    //调用第三种语法格式，将 [mylist1.begin(),mylist1.end())范围内的元素移动到 mylist.begin() 位置处                  
    mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());//mylist1:
                                                                             //mylist2:1 10 20 30 3 4 2
   
    cout << "mylist1 包含 " << mylist1.size() << "个元素" << endl;
    cout << "mylist2 包含 " << mylist2.size() << "个元素" << endl;
    //输出 mylist2 容器中存储的数据
    cout << "mylist2:";
    for (auto iter = mylist2.begin(); iter != mylist2.end(); ++iter) {
        cout << *iter << " ";
    }
    return 0;
}