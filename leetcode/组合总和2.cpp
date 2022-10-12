#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> frep;
    vector<vector<int>> rets;
    vector<int> nums;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        for(auto num : candidates){
            if(frep.empty() || num != frep.back().first){
                frep.emplace_back(num, 1);
            }else{
                frep.back().second++;
            }
        }

        dfs(0, target);

        return rets;
    }

    void dfs(int i, int target){
        if(target == 0){
            rets.push_back(nums);
            return;
        }
        if(i == frep.size() || target < frep[i].first){
            return;
        }

        dfs(i+1, target);

        int most = min(target / frep[i].first, frep[i].second);
        for(int j = 1; j <= most; ++j){
            nums.push_back(frep[i].first);
            dfs(i+1, target-j*frep[i].first);
        }
        for(int j = 1; j <= most; ++j){
            nums.pop_back();
        }
    }

};

int main(){
    vector<int> nums = {2,3,2,1,2,5};
    int target = 6;

    Solution P;
    vector<vector<int>> ret = P.combinationSum2(nums, target);

    for(int i = 0; i < ret.size(); ++i){
        for(int j = 0; j < ret[i].size(); ++j){
            cout << ret[i][j] << "," ;
        }
        cout << endl;
    }
}