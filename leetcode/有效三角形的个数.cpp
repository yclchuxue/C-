/**********************************
 * 有效三角形的个数----611
 * *******************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//方法1：暴力
//      排序后 a < b < c 
//         有 a + c > b    and     b + c > a
//      只需要 a + b > c
class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                int left = j+1, right = n-1, k = j;    //二分法
                while(left <= right)
                {
                    int mid = (left + right)/2;
                    if(nums[mid] < nums[i] + nums[j])
                    {
                        k = mid;
                        left = mid+1;
                    }
                    else
                    {
                        right = mid -1;
                    }
                }
                sum += k-j;
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> nums = {2,2,3,4};
    Solution P;

    int ret = P.triangleNumber(nums);

    cout << ret << endl;

    return 0;
}