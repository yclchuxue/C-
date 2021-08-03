/********************************************
 * 最短无序连续子数组
 * ******************************************/
#include <iostream>
#include <vector>
#include <limits.h>  //INT_MIN和INT_MAX的头文件
#include <algorithm> //sort排序函数的头文件
using namespace std;

//时间复杂度n*log(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0;
        while(nums[left] == numsSorted[left])
        {
            ++left;
        }
        int right = nums.size()-1;
        while(nums[right] == numsSorted[right])
        {
            --right;
        }
        return right - left + 1;
    }
};


//时间复杂度 n
class Solution_1 {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left  = -1;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(maxn > nums[i])
            {
                right = i;
            }
            else
            {
                maxn = nums[i];
            }
            if(minn < nums[n-i-1])
            {
                left = n-i-1;
            }
            else
            {
                minn = nums[n-i-1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

int main()
{
    Solution P;
    Solution_1 Q;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int ret = P.findUnsortedSubarray(nums);
    cout << ret << endl;
    int ret_1 = Q.findUnsortedSubarray(nums);
    cout << ret_1 << endl;

    return 0;
}

