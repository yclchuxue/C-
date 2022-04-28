#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Solution {
public:


    void sort_A(vector<int>& nums, int i, int j){
        srand(time(0));

        int len = (j-i+1);
        if(len <= 1){
            return ;
        }
        int pvoit_index = rand() % len + i;

        int pvoit = nums[pvoit_index];

        nums[pvoit_index] = nums[j];

        // cout << "pvoit = " << pvoit << endl;

        int right = j, left = i, flag = 0;

        while(right != left){
            if(flag == 0){
                if(nums[left] <= pvoit){
                    left++;
                }else{
                    nums[right] = nums[left];
                    flag = 1;
                }
            }else{
                if(nums[right] >= pvoit){
                    right--;
                }else{
                    nums[left] = nums[right];
                    flag = 0;
                }
            }
        }

        nums[left] = pvoit;
        
        // for(int x = 0; x < nums.size(); x++){
        //     cout << nums[x] << "\t";
        // }
        // cout << endl;
        // cout << "i = " << i << "\tleft-1 = " << left - 1 << endl;
        // cout << "j = " << j << "\tright+1 = " << right + 1 << endl;
        if(left-1 > i){
            sort_A(nums, i, left-1);
        }
        if(j > right + 1){
            sort_A(nums, left+1, j);
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        //sort(nums.begin(), nums.end());

        sort_A(nums, 0, nums.size()-1);

        return nums;
    }
};

int main()
{
    vector<int> nums = {9,10,45,8,6,5,2,3,1};

    Solution P;
    nums = P.sortArray(nums);

    for(auto it = nums.begin(); it != nums.end(); it++){
        cout << *it << "\t";
    }

    return 0;
}