#include <iostream>

using namespace std;

void wap_1(int **p, int **q);
void wap_2(int *&p, int *&q);

int main()
{
    int val_1 = 2, val_2 = 4;
    int *p = &val_1;
    int *q = &val_2;
    //cout << &val_1 << "\t" << p << endl;
    cout << "*p = " << *p << "\t*q = " << *q << endl;
    //cout << p << "\t" << q << endl;
    wap_1(&p, &q);

    //wap_2(p,q);

    //cout << "*p = " << *p << "\t*q = " << *q << endl;
    cout << p << "\t" << q << endl;

    return 0;
}

void wap_1(int **p, int **q)
{
    //cout << p << "\t" << q << endl;
    int *b = *p;
    *p = *q;
    *q = b;
    //cout << p << "\t" << q << endl;
}

void wap_2(int *&p, int *&q)
{
    //cout << p << "\t" << q << endl;
    int *b = p;
    p = q;
    q = b;
    //cout << p << "\t" << q << endl;
}