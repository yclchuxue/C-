// #include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    void print(vector<vector<int>> ret){
        cout << "ret is " << endl;
        for(int i = 0; i < ret.size(); ++i){
            for(int j = 0; j < ret[0].size(); ++j){
                cout << ret[i][j] << "\t";
            }
            cout << endl;
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() <= 1){
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),[](vector<int> a,vector<int> b){return a[0] < b[0];});
        vector<vector<int>> ret;
        int point1 = intervals[0][0], point2 = intervals[0][1];
        // bool ice = true;
        for(int i = 1; i < intervals.size(); ++i){
            // cout << point1 << "\t" << point2 << endl;

            if(intervals[i][0] <= point2){
                point2 = max(intervals[i][1], point2);
            }else{
                ret.push_back(vector<int>{point1, point2});
                point1 = intervals[i][0];
                point2 = intervals[i][1];
            }
        }
        // if(ice){
        ret.push_back(vector<int>{point1, point2});
        // }

        return ret;
    }
};

int main(){
    vector<vector<int>> nums = {
        {1,3},
        {19, 20},
        {2,6},
        {8,10},
        {15,18}
    };

    Solution P;

    vector<vector<int>> ret = P.merge(nums);

    P.print(ret);

    return 0;
}