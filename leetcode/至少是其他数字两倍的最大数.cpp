/***********************
 * 747. 至少是其他数字两倍的最大数
 * *********************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> ns = nums;
        if(nums.size() <= 1) return 0;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] >= nums[1] * 2){
            for(int i = 0; i < ns.size();i++){
                if(ns[i] == nums[0]) return i;
            }
        }else return -1;
        return 0;
    }
};

int main()
{
    vector<int> nums;
    int num;
    cin >> num ;
    for(int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n); 
    }
    Solution P;
    cout << "return :" << P.dominantIndex(nums) << endl;

    return 0;
}