#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s1 = "hello world";
    /*
    //1
    for(int index = 0; index < s1.size(); index++)
    {
        cout << s1[index] << endl;
    }
    //2
    for(auto c : s1)
    {
        cout << c << endl;
    }
    */
    /****3.6
    for(auto &c : s1)
    {
        c = 'X';
    }

    cout << s1 << endl;
    */
    cout << s1[0] << endl;

}