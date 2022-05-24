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

class Solution1 {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> rets;
        sort(nums.begin(), nums.end());
        if(n <= 2) return rets;

        for(int c = n - 1; c >= 2 ;){
            for(int a = 0, b = c - 1; a < b ; ){
                int count = nums[a] + nums[b];
                if(count < -1 * nums[c]){
                    ++a;
                }else if(count > -1 * nums[c]){
                    --b;
                }else{
                    rets.push_back(vector<int>{nums[a], nums[b], nums[c]});
                    do{
                        ++a;
                    }while(a < b && nums[a] == nums[a-1]);
                    do{
                        --b;
                    }while(a < b && nums[b] == nums[b+1]);
                }
            }
            do{
                --c;
            }while(c >= 2 && nums[c] == nums[c+1]);
        }

        return rets;
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