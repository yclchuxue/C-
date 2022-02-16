#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int abs(int a, int b){
        if(a >= b)  return a-b;
        else        return b-a;
    }

    //超时
    bool containsNearbyDuplicate_1(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j)
            {
                if(nums[i] == nums[j] && abs(i, j) <= k){
                    return true;
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j)
            {
                if(nums[i] == nums[j] && abs(i, j) <= k){
                    return true;
                }
            }
        }
        return false;
    }

};

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n >> k;
    for(int i = 0 ;i < n ; ++i){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    Solution P;
    cout << P.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}