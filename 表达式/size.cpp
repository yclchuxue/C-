#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int *p;
    char *b;

    cout << "all size is " << endl;
    cout << "int  *   = " << sizeof(p)        << endl;
    cout << "char *   = " << sizeof(b)        << endl;
    cout << "bool     = " << sizeof(bool)     << endl;
    cout << "cahr     = " << sizeof(char)     << endl;
    cout << "wchar_t  = " << sizeof(wchar_t)  << endl;
    cout << "char16_t = " << sizeof(char16_t) << endl;
    cout << "char32_t = " << sizeof(char32_t) << endl;
    cout << "int      = " << sizeof(int)      << endl;
    cout << "double   = " << sizeof(double)   << endl;
    cout << "float    = " << sizeof(float)    << endl;
    cout << "string   = " << sizeof(string)   << endl;
    cout << "vector<int>    = " << sizeof(vector<int>)    << endl;
    cout << "vector<string> = " << sizeof(vector<string>) << endl;
    cout << "vector<double> = " << sizeof(vector<double>) << endl;

    return 0;
}