/*************************
 * C++ primer 24题
 * **********************/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cout << "How long do you want the string ? ";
    int size{0};
    cin >> size;
    cin.ignore();       // 忽略输入长度 size 后的一个字符，如空格或换行符
    char *r = new char[size + 1]();     // size + 1 个值初始化为 0 的 char
    cin.get(r, size + 1);
    cout << "The input string is:\n\"" << r << "\"";

    // 释放动态数组
    delete [] r;

    return 0;
}