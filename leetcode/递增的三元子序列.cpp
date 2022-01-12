/*****************************
 * 334. 递增的三元子序列
 * **************************/

#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

//子数组（连续）
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num = 0;
        if(nums.size() < 3) return false;
        for(int j = 0; j < nums.size()-2;j++){
            num = 0;
            int X = nums[j];
            for(int i = j+1; i <= j+2; i++){
                if(X < nums[i]){
                    num++;
                    X = nums[i];
                }else{
                    break;
                }
                if(num >= 2) return true;
            }
            if(num >= 2)    return true;
        }
        return false;
    }
};
*/

//子序列（不连续）
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto e : nums) {
            if (e <= a) {
                a = e;
            } else if (e <= b) {
                b = e;
            } else {
                return true;
            }
        }
        return false;
    }
};


int main()
{
    vector<int> nums;
    int number;
    while(cin >> number){
        nums.push_back(number);
    }
    Solution P;
    cout << "\nreturn :" << P.increasingTriplet(nums) << endl;;


    return 0;
}