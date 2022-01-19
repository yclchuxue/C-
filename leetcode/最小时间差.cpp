/******************************
 * 539. 最小时间差
 * ***************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int abs(int a, int b){
        int n;
        if(a - b > 0)   n = a - b;
        else            n = b - a;
        if(n > 720)     n = 1440 - n;

        return n;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> nums;
        for(auto strs : timePoints){
            int num;
            num = ((int)strs[0] - 48)*10 + (int)strs[1] - 48;
            num = num*60 + ((int)strs[3] - 48)*10 + (int)strs[4] - 48;
            if(num >= 1440) return 0;
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min = abs(nums[0], nums[n-1]);
        for(int i = 1; i < n; i++){
            if(min > abs(nums[i-1], nums[i])){
                min = abs(nums[i-1], nums[i]);
            }
        }
        return min;
    }
};

int main()
{
    vector<string> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string strs;
        cin >> strs;
        nums.push_back(strs);
    }
    Solution P;
    cout << P.findMinDifference(nums) << endl;

    return 0;
}