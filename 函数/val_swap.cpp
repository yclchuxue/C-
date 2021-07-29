/*********************************
 * 交换两个数的值
 * ******************************/
#include <iostream>

using namespace std;

void swap(int *p, int *q);

int main()
{
    int val_1, val_2;
    cout << "输入两个int型的数:" ;
    cin  >> val_1 >> val_2;
    cout << "val_1 = " << val_1 << "\tval_2 = " << val_2 << endl;
    
    swap(&val_1, &val_2);

    cout << "val_1 = " << val_1 << "\tval_2 = " << val_2 << endl;

    return 0;
}

void swap(int *p, int *q)
{
    int val = *p;
    *p = *q;
    *q = val;
}