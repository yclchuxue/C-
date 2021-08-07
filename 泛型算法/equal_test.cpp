/***********************************
 * 测试equal算法
 * ********************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> values_1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> values_2 = {1, 2, 3, 4};
    bool ret = equal(values_2.begin(), values_2.end(), values_1.begin());
    cout << ret << endl;    //1

    vector<string> str_1 = {"hello", " ", "world"};
    vector<string> str_2 = {"hello", " "};
    bool ret_1 = equal(str_1.begin(), str_1.end(), str_2.begin());
    cout << ret_1 << endl;  //0

    return 0;
}