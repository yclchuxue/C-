#include <iostream>

using namespace std;

void add(int a) 
{
    // lambda 捕获它所在 add 函数中的变量 a
    auto sum = [a] (int b) { return a + b; };
    cout << sum(4) << endl;		// b = 4

}
int main() 
{

    add(1);		// 调用函数 add，形参 a = 1
    add(2);		// 调用函数 add，形参 a = 2

    return 0;
}