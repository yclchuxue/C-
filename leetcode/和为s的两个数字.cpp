#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len-1;
        // vector<int> rets;
        while(left < right){
            if(target-nums[left] < nums[right]){
                --right;
            }else if(target-nums[left] > nums[right]){
                ++left;
            }else{
                return vector<int>{nums[left], nums[right]};
            }
        }

        return vector<int>{};
    }
};