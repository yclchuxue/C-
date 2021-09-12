/*********************************
 * leetcode----二分查找-----704
 * *******************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, mid = l+(r-l)/2, ret = -1;
        while(l <= r)
        {
            if(nums[mid] == target)
            {
                ret = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
                mid = l+(r-l)/2;
            }
            else
            {
                r = mid -1;
                mid = l+(r-l)/2;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 3, 5, 4, 8, 9, 6, 10};
    int target = 5, ret;
    Solution S;
    ret = S.search(nums, target);

    cout << ret << endl;

    return 0;   
}