#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int trap(vector<int> &height)
	{
		int n = height.size();
		// left[i]表示i左边的最大值，right[i]表示i右边的最大值
		vector<int> left(n), right(n);
		for (int i = 1; i < n; i++)
		{
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--)
		{
			right[i] = max(right[i + 1], height[i + 1]);
		}
		int water = 0;
		for (int i = 0; i < n; i++)
		{
			int level = min(left[i], right[i]);
			water += max(0, level - height[i]);
		}
		return water;
	}
};

int main()
{
	vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	Solution P;

	P.trap(nums);
}