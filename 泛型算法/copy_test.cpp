/***********************************
 * 测试copy算法
 * ********************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int val_1[5] = {0, 1, 2, 3, 4};
    int val_2[10] = {0,0,0,0,0,5,6,7,8,9};
    copy(begin(val_1), end(val_1), begin(val_2));

    for(auto i : val_2)
    {
        cout << i << "\t";
    }
    cout << endl;

    copy(begin(val_2), end(val_2), begin(val_1));
    for(auto i : val_1)
    {
        cout << i << "\t";
    }
    cout << endl;


    return 0;
}