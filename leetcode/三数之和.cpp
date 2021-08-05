/************************************
 * 三数之和-------------15
 * *********************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > 0) return ret;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int left = i+1, right = n-1;
            while(left < right)
            {
                if(nums[left] + nums[right] > -nums[i])
                {
                    --right;
                }
                else if(nums[left] + nums[right] < -nums[i])
                {
                    ++left;
                }
                else
                {
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(nums[left] == nums[left-1] && left < right)
                    {
                        ++left;
                    }
                    while(nums[right] == nums[right+1] && left < right)
                    {
                        --right;
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution P;

    vector<vector<int>> ret = P.threeSum(nums);

    for(int i = 0; i < ret.size();++i)
    {
        for(int j = 0; j < ret[0].size();++j)
        {
            cout << ret[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}