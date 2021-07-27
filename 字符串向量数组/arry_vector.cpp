#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int arry[5] = {0, 1, 2, 3, 4};
    vector<int> vec(begin(arry), end(arry));   //数组初始化vector
    for(auto c : vec)
    {
        cout << c << " ";
    }
    cout << endl;

    int arr[5];
    int *pbeg = begin(arr);
    int *pend = end(arr);
    for(int i = 0; pbeg != pend;++pbeg,i++)     //vextor初始化数组
    {
        *pbeg = vec[i];
    }
    for(auto c : arr)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}