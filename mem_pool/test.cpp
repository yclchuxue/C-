#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "memmory_pool.h"

using namespace std;

int main()
{
    cout << "AAAAAAAAA" << endl;
    memmory_pool MEM;
    cout << "BBBBBBBBB" << endl;

    NODE *p = MEM.my_malloc(1);

    cout << "DDDDDDDDD" << endl;
    MEM.my_free(p);
    cout << "FFFFFFFFF" << endl;

    return 0;
}