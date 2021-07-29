/****************************
 * 阶乘函数，输入int，输入阶乘
 * *************************/
#include <iostream>

using  namespace std;

int factorial(int val);

int main()
{
    int val, val_fact;
    cout << "输入一个int型的数: " ;
    cin >>val;

    val_fact = factorial(val);

    cout << "val_fact = " << val_fact << endl;

    return 0;
}

int factorial(int val)
{
    int val_fact = 1;
    while(val != 1)
    {
        val_fact *= val;
        --val;
    }
    return val_fact;
}