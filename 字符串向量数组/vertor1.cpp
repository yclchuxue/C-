/********************************
 * 习题3.20
 * *****************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
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
        values.push_back(val);
    }
    for(decltype(values.size()) index = 0, len = values.size(); index < len; index++)    //下标/索引
    {
        cout << values[index] << " + " << values[len-1-index] << " = " << values[len-1-index] + values[index] << endl;
    }
    cout << endl;

    return 0;
}