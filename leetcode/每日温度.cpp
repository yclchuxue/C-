#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> rets(len, 0);

        stack<vector<int>> stacks;

        for(int i = 0; i < len; ++i){
            if(stacks.empty()){
                // cout << "push null " << temperatures[i] << "\t" << i << endl;
                stacks.push(vector<int>{temperatures[i], i});
            }else{
                while(!stacks.empty()){
                    auto nums = stacks.top();
                    
                    
                    if(nums[0] < temperatures[i]){
                        // cout << "pop" << nums[0] << "\t" << nums[1] << endl;
                        rets[nums[1]] = i - nums[1];
                        stacks.pop();
                    }

                    if(nums[0] >= temperatures[i] || stacks.empty()){
                        // cout << "push" << temperatures[i] << "\t" << i << endl;
                        stacks.push(vector<int>{temperatures[i], i});
                        break;
                    }
                }
            }
        }

        return rets;
    }
};