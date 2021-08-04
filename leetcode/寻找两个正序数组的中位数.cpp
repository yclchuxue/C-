/*****************************************
 * 寻找两个正序数组的中位数-------4
 * **************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//方法1,复杂度较高
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums2.size();
        for(int i = 0; i < n; ++i)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        int m = nums1.size();
        if(m&1 == 1)
        {
            n = (m-1)/2;
            return nums1[n];
        }
        else
        {
            n = m/2 - 1;
            return (nums1[n] + nums1[n+1])/2.0;
        }
    }
};

int main()
{
    Solution P;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    double ret = P.findMedianSortedArrays(nums1, nums2);
    cout << ret << endl;

    return 0;
}