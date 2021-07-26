#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    double sum = 50.2;
    const int &h = sum;

    int i = 100, j = 50;
    int *p = &i, *q = &j;

    cout << i << " " << *p << " " << p << " " << &p <<endl;
    cout << j << " " << *q << " " << q << " " << &q <<endl;

    return 0;
}