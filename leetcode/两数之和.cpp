#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int len = nums.size();
        for(int a = 0; a < len; ++a){
            auto it = hash.find(target - nums[a]);
            if(it != hash.end()) {
                vector<int> rets = {it->second, a};
                return rets;
            }

            hash[nums[a]] = a;
        }   
        return {};
    }
};


int main(){
    return 0;
}