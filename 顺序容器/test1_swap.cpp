/***************************************
 * 测试swap函数交换后，迭代器，引用，指针的变化
 * ************************************/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    vector<int> nums1 = {1,3,5,7,9};
    vector<int> nums2 = {2,4,6,8,10};
    auto iter_1 = nums1.begin();
    auto iter_2 = nums2.begin();
    auto *point_1 = &nums1[0];
    auto *point_2 = &nums2[0];
    vector<int> &num1 = nums1;
    vector<int> &num2 = nums2;
    cout << "*iter_1 = " << *iter_1 << endl;
    cout << "*iter_2 = " << *iter_2 << endl;

    swap(nums1, nums2);                                //swap后nums1和nums2的值发生了交换
    cout << "*iter_1 = " << *iter_1 << endl;           //迭代器iter1变为nums2的迭代器
    cout << "*iter_2 = " << *iter_2 << endl;           //迭代器iter2变为nums1的迭代器

    cout << "nums2: iter_1--->nums2.end()" << endl;
    while(iter_1 != nums2.end())         //用迭代器iter_1打印nums2
    {
        cout << *iter_1 << "\t";
        ++iter_1;
    }
    cout << endl;

    cout << "nums1: iter_2--->nums1.end()" << endl;
    while(iter_2 != nums1.end())         //用迭代器iter_2打印nums1
    {
        cout << *iter_2 << "\t";
        ++iter_2;
    }
    cout << endl;

    cout << "&num1" << endl;            //引用仍然为nums1，num1的结果随nums1改变
    for(int &i : num1)
    {
        cout << i << "\t";
    }
    cout << endl;

    cout << "&num2" << endl;            //引用仍然为nums2，nums2的结果随nums2改变
    for(int &i : num2)
    {
        cout << i << "\t";
    }
    cout << endl;

    cout << "*point_1 = " << *point_1 << endl;      //交换后指针值为改变，但指向了nums2[0]
    cout << "*point_2 = " << *point_2 << endl;      //交换后指针值为改变，但指向了nums1[0]

    return 0;
}