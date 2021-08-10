#include <iostream>

using namespace std;

int main() 
{
    int i = 2;
    
    auto add1 = [] (int lhs, int rhs) { return lhs + rhs; };
    // lambda 捕获它所在 main 函数中的变量 i
    auto add2 = [i] (int num) { return i + num; };


    cout << "add1(1, 2): " << add1(1, 2) << endl;
    cout << "add2(3)   : " << add2(3) << endl;

    return 0;
}