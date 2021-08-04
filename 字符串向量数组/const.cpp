#include <iostream>
using namespace std;

int main()
{
    
    int a = 50;
    int b = 40;
    const int *const p = &a;

    cout << "a = "    << a    << endl;

    cout << "*p = " << *p <<  endl;
    //p = &b;
    //*p = 400;
    cout << "*p = " << *p <<  endl;
    

    return 0;
}