#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//动态规划

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> fi;

        fi.push_back(nums[0]);
        int max = fi[0];

        for(int i = 1; i < nums.size(); ++i){
            if(fi[i-1] + nums[i] >= nums[i]){
                fi.push_back(fi[i-1] + nums[i]);
            }else{
                fi.push_back(nums[i]);
            }

            if(fi[i] > max){
                max = fi[i];
            }
        }

        return max;
    }
};

int main(){

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    Solution P;
    
    cout << P.maxSubArray(nums) << endl;

    return 0;
}