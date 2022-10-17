#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();
        if(len <= 1){
            return ;
        }
        int t = len - 1, ice = -1;
        int target = nums[t];
        for(int i = len-2; i >= 0; ){
            if(nums[i] < nums[t]){
                target = nums[i];
                t = i;
                ice = 1;
                break;
            }else{
                t = i;
                i--;
            }
        }
        
        // cout << ice << " ? " << t << endl;

        if(ice == 1){
            for(int i = len -1; i >= 0; i--){
                if(nums[i] > target){
                    // cout << t << " " << i << endl;
                    swap(nums[t], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + t + 1, nums.end());
        }else{
            reverse(nums.begin(), nums.end());
        }
        
    }
};

class Solution1
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len_nums = nums.size();
        if(len_nums < 2){
            return ;
        }

        auto left = nums.end() - 2, right = nums.end() - 1, it = nums.end();
        int ice = 0;

        while(right != nums.begin()){
            if( *left < *right){ 
                int min = right - nums.begin();
                int i = min + 1;
                while(i < len_nums){
                    if(nums[i] > *left){
                        if(nums[i] < nums[min]){
                            min = i;
                        }
                    }
                    i++;
                }

                int num = *left;
                *left = nums[min];
                nums[min] = num;
                ice = 1;
                break;
            }else{
                left--;
                right--;
                it--;
            }
        }
        if(ice){
            sort(right, nums.end());
        }else{
            sort(nums.begin(), nums.end());
        }
        return;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1};

    Solution P;

    P.nextPermutation(nums);

    for (auto iter = nums.begin(); iter != nums.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;


    return 0;
}

// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
// 1 4 2 3
// 1 4 3 2
// 2 1 3 4
// 2 1 4 3
// 2 3 1 4
// 2 3 4 1
// 2 4 1 3
// 2 4 3 1
// 3 1 2 4
// 3 1 4 2
// 3 2 1 4
// 3 2 4 1
// 3 4 1 2
// 3 4 2 1
// 4 1 2 3
// 4 1 3 2
// 4 2 1 3
// 4 2 3 1
// 4 3 1 2
// 4 3 2 1