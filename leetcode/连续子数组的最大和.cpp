#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        if(len < 2) return nums[0];
        int max_num = nums[0], ret = nums[0];
        for(int i = 1; i < len; ++i){
            max_num = max(max_num+nums[i], nums[i]);
            ret = max(max_num, ret);
        }
        return ret;
    }
};