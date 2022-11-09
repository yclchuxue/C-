#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    //双指针--失败
    void sortColors1(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        if(len <= 1){
            return ;
        }

        while(left < right){
            if(nums[left] > nums[right]){
                int t = nums[left];
                nums[left] = nums[right];
                nums[right] = t;
            }

            if(nums[left] < nums[right]){
                if(nums[left] == 0){
                    left++;
                }

                if(nums[right] == 2){
                    right--;
                }
            }

            if(nums[left] == nums[right] && nums[left] == 1){
                int index_1 = 0, index_2 = 0;
                for(index_1 = left+1; index_1 < right)
            }
        }
    }

    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){
                nums[num2++] = 2;
                nums[num1++] = 1;
                nums[num0++] = 0;
            }else if (nums[i] == 1){
                nums[num2++] = 2;
                nums[num1++] = 1; 
            }else{
                nums[num2++] = 2;
            }
        }
    }
};

int main(){
    vecter<int> nums = {2,1,0,2,1,0};

    Solution P;

    P.sortColors(nums);


}