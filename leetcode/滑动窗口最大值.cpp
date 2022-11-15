#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> qu;
        int i;
        for (i = 0; i < k; i++)
        {
            qu.emplace(nums[i], i);
        }
        vector<int> rets;
        rets.push_back(qu.top().first);

        for (; i < nums.size(); i++)
        {
            qu.emplace(nums[i], i);
            if (!qu.empty())
            {
                while (qu.top().second <= i - k)
                {
                    qu.pop();
                }
            }
            rets.push_back(qu.top().first);
        }

        return rets;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution P;

    vector<int> rets = P.maxSlidingWindow(nums, k);

    for (int i = 0; i < rets.size(); i++)
    {
        cout << rets[i] << "\t";
    }
    cout << endl;
}