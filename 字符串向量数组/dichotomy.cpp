/******************************
 * 迭代二分法 vector and iterator
 * ***************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int val, flag, mark = 0;
    vector<int> values;

    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        values.push_back(val);
    }

    cout << "请输入你要查询的数：" ;

    cin >> flag;

    cout << flag << endl;

    auto it_left = values.begin();
    auto it_right = values.end();
    auto mid = it_left + values.size()/2;
    while(it_left != it_right -1)
    {
        if(*mid == flag)
        {
            mark = 1;
            break;
        }
        else if(*mid < flag)
        {
            //it_left = mid;   不能直接这样拷贝
            //cout << "mid = " << *mid << endl;
            it_left += mid - it_left;
            mid = it_left + (it_right-it_left)/2;
            //cout << "*it_left = " << *it_left << "mid = " << *mid << endl;
        }
        else if(*mid > flag)
        {
            //it_right = mid;
            //cout << "mid = " << *mid << endl;
            it_right -= it_right - mid;
            mid = it_right - (it_right - it_left)/2;
            //cout << "*it_left = " << *it_left << "mid = " << *mid << endl;
        }
    }

    if(mark)
    {
        cout << "存在数" << flag << endl;
    }
    else
    {
        cout << "不存在数" << flag << endl;
    }

    return 0;
}