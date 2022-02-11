/************************************
 * 学生分数的最小差值-------1984
 * *********************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min = nums[n-1] - nums[n-k];
        while(n-k > 0)
        {
            --n;
            int m = nums[n-1] - nums[n-k];
            if(min > m)
            {
                min = m;
            }
        }
        return min;
    }   
};

int main()
{
    vector<int> nums;
    int num, k, i = 0;
    cin >> num >> k;
    while(i < num)
    {
        int n;
        cin >> n;
        nums.push_back(n);
        ++i;
    } 
    Solution P;
    int ret = P.minimumDifference(nums, k);
    cout << "return :\t" << ret << endl;

    return 0;
}