/***********************************
 * 绝对值函数   输入一个int，输出它的绝对值
 * ********************************/
#include <iostream>

using namespace std;

int abs_val(int val);

int main()
{
    int val, val_abs;
    cout << "请输入一个int型的数：";
    cin >> val;

    val_abs = abs_val(val);

    cout << "val_abs = " << val_abs << endl;

    return 0;
}

int abs_val(int val)
{
    int val_abs;
    if(val >= 0)
    {
        val_abs = val;
    }
    else
    {
        val_abs = (-1)*val;
    }

    return val_abs;
}