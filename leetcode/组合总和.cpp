#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& rets, vector<int>& nums, int index){
        if(index == candidates.size()){
            return;
        }
        if(target == 0){
            rets.push_back(nums);
            return;
        }

        dfs(candidates, target, rets, nums, index+1);
        if(target-candidates[index] >= 0){
            nums.push_back(candidates[index]);
            dfs(candidates, target-candidates[index], rets, nums, index);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> rets;

        dfs(candidates, target, rets, nums, 0);

        return rets;
    }
};