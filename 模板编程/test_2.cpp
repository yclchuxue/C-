#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T> constexpr int compare(const T &v1, const T &v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return  1;
    return 0;
}

template <unsigned N, unsigned M> inline int compare_1(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

int main()
{
    string strs_1 = "lajbdvjlak", strs_2 = "jbdsaljdb";
    double val_1 = 13.3, val_2 = 13.3;

    cout << compare(strs_1, strs_2) << endl;
    cout << compare(val_1, val_2)   << endl;
    cout << compare_1("abc", "abc") << endl;

    return 0;
}