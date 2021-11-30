/***************************************
 * 回旋镖的数量------------------447（×）
 * ************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        if(points.size() <= 2)
        {
            return 0;
        }
        int num = 0;
        
        for(int i = 0; i < points.size()-1; ++i)
        {
            vector<double> nums;
            for(int j = i+1; j < points.size(); ++j)
            {
                double ss = (points[j][0] - points[i][0])*(points[j][0] - points[i][0])
                            +(points[j][1] - points[i][1])*(points[j][1] - points[i][1]);
                double s_xy = pow(ss, 1/2); 
                nums.push_back(s_xy); 
            }
            sort(nums.begin(), nums.end());
            double n = nums[0];
            for(auto i = nums.begin()++; i != nums.end(); ++i)
            {
                if(n == *i)
                {
                    ++num;
                }
                else
                {
                    n = *i;
                }
            }
            cout << "num = " <<num << endl;
            for(auto i : nums)
            {
                cout << i << "\t";
            }
        }

        

        

        

        return num*2;
    }
};

int main()
{
    vector<vector<int>> points;
    int val_x, val_y;
    while(cin >> val_x >> val_y)    //EOF结束输入
    {
        vector<int> val_xy = {val_x, val_y};
        points.push_back(val_xy);
    }

    Solution S;
    int ret = S.numberOfBoomerangs(points);

    cout << ret << endl;

    return 0;
}