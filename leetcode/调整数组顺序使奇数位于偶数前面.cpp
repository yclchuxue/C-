#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len-1;

        while(left < right){
            while (left<right && nums[left] % 2 == 1) {
                ++left;
            }

            while(left<right && nums[right] % 2 == 0) {
                --right;
            }

            if (left < right) {
                swap(nums[left++], nums[right--]);
            }
        }

        return nums;
    }
};