/************************************
 * C++ primer----拷贝赋值销毁----15题
 * *********************************/
#include <iostream>

using namespace std;

class numbered {
private:
    static int seq;
public:
    numbered() { mysn = seq++; }
    // 13.15
    numbered(numbered &n) { mysn = seq++; }
    int mysn;
};

int numbered::seq = 0;

// 13.16
// void f(const numbered &s)
void f(const numbered s) {
    cout << s.mysn << endl;
}

int main() {

    numbered a, b = a, c = b;      //调用拷贝赋值函数
    cout << a.mysn << b.mysn << c.mysn << endl;
    f(a); f(b); f(c);        //调用函数时会调用拷贝构造函数

    return 0;
}