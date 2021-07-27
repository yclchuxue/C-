/*******************************
 * 数组使用
 * ****************************/
#include <iostream>
#include <cstddef>
using namespace std;
using four = int[4];
typedef size_t st;

int main()
{
/*
    int val[10] = {0,1,2,3,4,5,6,7,8,9};

    int *beg = begin(val); 
    //int *beg = val;
    //int *en   = &val[10];    //指向数组最后一位的下一个地址  容易出错
    int *en = end(val);        //指向数组最后一位的下一个地址


    while(beg != en)
    {
        cout << *beg << "\t";
        beg++;
    }
    cout << endl;
*/
//3.43
    int val[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    //1.0
    for(int (&p)[4] : val)
    {
        for(int b : p)
        {
            cout << b << "\t";
        }
        cout << endl;
    }
    //2.0
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << val[i][j] << "\t";
        }
        cout << endl;
    }
    //3.0
    for(int (*p)[4] = val; p != val + 3;p++)
    {
        for(int *b = *p; b != *p + 4; b++)
        {
            cout << *b << "\t";
        }
        cout << endl;
    }
    //4.0
    for(four *p = val; p != val +3; p++)
    {
        for(int *b = *p; b != *p + 4; b++)
        {
            cout << *b << "\t";
        }
        cout << endl;
    }
    //5.0
    for(st i; i < 3; i++)
    {
        for(st j = 0; j < 4; j++)
        {
            cout << val[i][j] << "\t";
        }
        cout << endl;
    }
    //6.0
    for(auto p = val; p != val + 3; p++)
    {
        for(auto b = *p; b != *p + 4; b++)
        {
            cout << *b << "\t";
        }
        cout << endl;
    }
    //7.0
    for(auto i = 0; i < 3; i++)
    {
        for(auto j = 0; j < 4; j++)
        {
            cout << val[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}