#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int val;
    vector<int> values;

    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        //val *= 2;
        values.push_back(val);
    }

    for(auto it = values.begin(); it != values.end(); ++it)     //迭代器
    {
        *it = (*it)*2;
    }

    for(auto it = values.begin(); it != values.end(); ++it)
    {
        cout << *it << "\t";
    }
    cout << endl;

    return 0;
}