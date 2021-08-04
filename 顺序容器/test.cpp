/******************************
 * C++ primer 9.4
 * ***************************/
#include <iostream>
#include <vector>

using namespace std;

bool findval(vector<int>::const_iterator beg, vector<int>::const_iterator end, int value)
{
    while(beg != end)
    {
        if(*beg == value)
        {
            return true;
        }
        ++beg;
    }
    return false;
}

int main()
{
    vector<int> values {1,2,3,4,5,6,7,8,9,10};
    int value = 4;
    bool ret = findval(values.begin(), values.end(), value);
    cout << ret << endl;

    return 0;
}