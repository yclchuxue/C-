#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int sort_q(vector<int> &nums, int i, int j, int index){

        if(j - i + 1 <= 1){
            return 0;
        }

        srand(time(0));
        int point_index = rand() % (j - i + 1) + i;

        int point = nums[point_index];

        nums[point_index] = nums[j];

        int left = i;

        int right = j;

        int flag = 1;

        while(left < right){
            if(flag == 1){
                if(nums[left] <= point){
                    nums[right] = nums[left];
                    right--;
                    flag = 0;
                }else{
                    left++;
                }
            }else{
                if(nums[right] >= point){
                    nums[left] = nums[right];
                    left++;
                    flag = 1;
                }else{
                    right--;
                }
            }
        }

        nums[left] = point;

        sort_q(nums, i, left-1, 1);
        if(index == 1){
            sort_q(nums, left+1, j, 1);
        }
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {

        if(nums.size() == 1 && k == 1){
            return nums[0];
        }

        int x = sort_q(nums, 0, nums.size()-1, 0);
        cout << x << endl;
        while(1){
            if(x > k-1 || x == 0){
                break;
            }else{
                x = sort_q(nums, x+1, nums.size()-1, 0);
                cout << x << endl;
            }
        }    

        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << "\t";
        }
        cout << endl;

        return nums[k-1];
    }
};

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    Solution P;

    cout << P.findKthLargest(nums, k) << endl;

    return 0;
}