#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len-1;
        while (left < right) {
            int mid = (right - left)/2 + left;

            if(nums[mid] != mid){
                right = mid;
            }else{
                if(mid + 1 < len)   left = mid+1;
                else                left = mid;
            }
        }
        if(nums[left] != left)  return left;
        else                    return left+1;
    }
};