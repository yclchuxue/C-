#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
public:
    int getindex(vector<int>& nums, int target, bool lower){
        int len = nums.size();
        int left = 0, right = len-1;

        while(left < right){
            int mid = (right - left) / 2 + left;
            if(nums[mid] < target) { 
                left++;
            }
            if(nums[mid] > target) {
                right--;
            }

            if(nums[mid] == target){
                if(lower){
                    if(mid-1 >= 0){
                        if(nums[mid-1] != target)   return mid;
                        else right = mid - 1;
                    }else{
                        right = mid;
                    }
                }else{
                    if(mid+1 < len){
                        if(nums[mid+1] != target)   return mid;
                        else left = mid + 1;
                    }else{
                        left = mid;
                    }
                }
            }
        }

        return left;
    }

    int search(vector<int>& nums, int target) {
        int left_index  = getindex(nums, target, true);
        int right_index = getindex(nums, target, false); 
        if(left_index <= right_index && left_index >= 0 && right_index < nums.size() && nums[right_index] == nums[left_index] && nums[left_index] == target) {
            return right_index - left_index + 1;
        }
        return 0;
    }
};