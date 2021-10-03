#include <algorithm>
#include <iostream>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
    int val = 40;

    int *itr = new int(100);

    unique_ptr<int> p(new int(40));

    unique_ptr<int> q(itr);

    cout << *p << endl;

    cout << *q << endl;

    return 0;
}