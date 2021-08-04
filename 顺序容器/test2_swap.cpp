/***************************************
 * 测试swap函数交换后，迭代器，引用，指针的变化
 * *************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "world";
    string *point_1 = &str1;
    string *point_2 = &str2;
    string& st1 = str1;
    string& st2 = str2;
    auto iter_1 = str1.begin();
    auto iter_2 = str2.begin();

    swap(str1, str2);
    cout << "*point_1 = " << *point_1 << "\n" << "*point_2 = " << *point_2 << endl;

    cout << "st1 = " << st1 << "\n" << "st2 = " << st2 << endl;

    cout << "*iter_1 = " << *iter_1 << "\n" << "*iter_2 = " << *iter_2 << endl;

    return 0;
}