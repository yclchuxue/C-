/**************************************
 * leetcode---面试题 17.14. 最小K个数
 * ***********************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int get_min(vector<int>& arr, int l, int r)
    {
        int mid = rand()%(r-l+1)+l;
        swap(arr[mid], arr[r]);
        int num = l-1;

        for(int i = l; i < r; ++i)
        {
            if(arr[i] <= arr[r])
            {
                ++num;
                swap(arr[num], arr[i]);
            }
        }
        swap(arr[num+1], arr[r]);

        return num+1;
    }

    void get_num(vector<int>& arr, int l, int r, int k)
    {
        if(l >= r) return ;
        int num = get_min(arr, l, r);
        int pos = num -l +1;
        if(k == pos)
        {
            return ;
        }
        else if(k < pos)
        {
            get_num(arr, l, num-1, k);
        }
        else
        {
            get_num(arr, num+1, r, k-pos);
        }
    }
public:
    vector<int> smallestK_1(vector<int>& arr, int k) 
    {
        vector<int> rets;
        sort(arr.begin(), arr.end());     //使用sort排序
        for(int i = 0; i < k; ++i)
        {
            rets.push_back(arr[i]);
        }

        return rets;
    }

    vector<int> smallestK_2(vector<int>& arr, int k)
    {
        srand((unsigned)time(NULL));
        get_num(arr, 0, (int)arr.size()-1, k);

        vector<int> rets;
        for(int i = 0; i < k; ++i)
        {
            rets.push_back(arr[i]);
        }

        return rets;
    }
};

int main()
{
    vector<int> values = {1,3,5,7,2,4,6,8};
    int k = 4;
    Solution S;

    vector<int> rets = S.smallestK_2(values, k);

    for(auto itr = rets.begin(); itr != rets.end(); ++itr)
    {
        cout << *itr << "\t";
    }
    cout << endl;

    return 0;
}