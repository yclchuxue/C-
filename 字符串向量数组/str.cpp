#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    string s1, s2;
/**********3.2
    getline(cin, s1);       //一次读入一整行
    cout << s1 << endl;

    cin >> s1;              //一次读入一个词
    cout << s1 << endl;
*/
/***********3.4
    getline(cin, s1);
    getline(cin, s2);

    if(s1 == s2)
        cout << "相等" << endl;
    else
    {
        cout << "较大的为：";
        if(s1 > s2)
        {
            cout << s1 <<endl;
        }          
        else
        {
            cout << s2 <<endl;
        }
    }
    if(s1.size() != s2.size())
    {
        cout << "长度较大的为：";
        if(s1.size() > s2.size())
        {
            cout << s1 <<endl;
        }          
        else
        {
            cout << s2 <<endl;
        }
    }
*/
//3.5
    while(getline(cin, s1))
    {
        if(s1 == "exit")
        {
            break;
        }
        //s2 = s2 + s1;
        s2 = s2 + " " + s1;
    }

    cout << s2 << endl;

    return 0;
}