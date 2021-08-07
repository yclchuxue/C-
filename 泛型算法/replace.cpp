#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums_1 = {0,3,2,3,4,5,3,7};
    vector<int> nums_2;                        //第三个参数要使用插入迭代器，无法使用begin
    vector<int> nums_3 = {1};                  //第三个参数可以使用begin
    replace(nums_1.begin(), nums_1.end(), 3, 0);
    for(auto i : nums_1)
    {
        cout << i << "\t";
    }
    cout << endl;

    replace_copy(nums_1.begin(), nums_1.end(), back_inserter(nums_2), 0, 3);
    for(auto i : nums_2)
    {
        cout << i << "\t";
    }
    cout << endl;

    replace_copy(nums_1.begin(), nums_1.end(), nums_3.begin(), 0, 3);
    for(auto i : nums_2)
    {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}