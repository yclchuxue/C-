/******************************
 * 540. 有序数组中的单一元素
 * ***************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ice = 0, i = 0, j = 1, ret,n = nums.size();
        for(;j < n-1;)
        {
            if(nums[i] == nums[j])
            {
                i += 2;
                j += 2;
            }else{
                ice = 1;
                ret = nums[i];
                break;
            }
        }
        if(ice == 0){
            return nums[n-1];
        }else{
            return ret;
        }
    }
};

int main()
{
    int n;
    vector<int> nums;
    while(cin >> n){
        if(n == -1){
            break;
        }
        nums.push_back(n);
    }

    Solution P;
    cout << P.singleNonDuplicate(nums) << endl;


    return 0;
}