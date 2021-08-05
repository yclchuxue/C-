/*********************************
 * 盛最多水的容器-------11
 * ******************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max = 0, i = 0, j = height.size()-1,sum = 0;
        while(i < j) 
        {
            if(height[i] <= height[j])
            {
                sum = (j-i)*height[i];
                ++i;
            }
            else
            {
                sum = (j-i)*height[j];
                --j;
            }
            if(sum > max) max = sum;
        }
        return max;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution P;
    int ret = P.maxArea(height);

    cout << ret << endl;

    return 0;
}