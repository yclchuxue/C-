#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        vector<int> rets = nums;
        rets.push_back(-1);
        for(int i = 0; i < len+1; i++){
            if(rets[i] < 0){
                rets[i] = len+1;
            }
        }
        
        for(int i = 0; i < len; i++){
            if(nums[i] >= 0 && nums[i] <= len){
                rets[nums[i]] = -1;
            }
        }

        for(int i = 0; i < len+1; i++){
            cout << rets[i] << "\t";
        }
        cout << endl;

        for(int i = 1; i < len+1; i++){
            if(rets[i] >= 0){
                return i;
            }
        }
        return len+1;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, -8, 10, 0};

    Solution P;

    cout << P.firstMissingPositive(nums) << endl;
}