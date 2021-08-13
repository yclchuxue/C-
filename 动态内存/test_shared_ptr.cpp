#include <iostream>
#include "StrBlob.h"

using namespace std;

int main() 
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    // b2 在花括号外失效，作用域仅限于花括号内
    // cout << b2.size() << endl;
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    return 0;
}