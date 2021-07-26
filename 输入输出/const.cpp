#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int i = 10;
    int &p = i;
    const int &q = i;
    cout << i << " " << p << " " << q <<endl;

    p = 20;

    cout << i << " " << p << " " << q <<endl;

    return 0;
}