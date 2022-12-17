#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int k = nums[i];
            if(k < 0) k += len;
            if(nums[k] < 0) return k;
            nums[k] -= len;
        }

        return -1;
    }
};