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

class Solution1{
public:

    int sort_q_one(vector<int>& nums, int l_index, int r_index){
        
        if(r_index-l_index+1 <= 1){
            return l_index;
        }
        
        srand(time(0));
        int point_index = rand() % (r_index-l_index+1) + l_index;
        int point = nums[point_index];
        cout << "point_index = " << point_index << " point = " << point << "\t" << l_index << " " << r_index << endl;
        nums[point_index] = nums[r_index];
        int left = l_index;
        int right = r_index;
        int flag = 1;

        while(left < right){
            if(flag){
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
        return left;
    }

    void print(vector<int>& nums, int left, int right){
        for(int i = 0; i <= right; i++){
            cout << nums[i] << "\t";
        }
        cout << endl;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len_num = nums.size();
        if(len_num == 1 && k == 1){
            return nums[0];
        }
        int left = 0, right = len_num -1;
        int x = sort_q_one(nums, left, right);
        cout << "x = " << x << endl;
        print(nums, left, right);
        while(1){
            if(x > k-1){
                right = x - 1;
                x = sort_q_one(nums, left, right);
                cout << "x1 = " << x << endl;
                print(nums, left, right);
            }else if(x < k-1){
                left = x + 1;
                x = sort_q_one(nums, left, right);
                cout << "x2 = " << x << endl;
                print(nums, left, right);
            }else{
                return nums[k-1];
            }
        }

        return nums[k-1];
    }
};

int main(){
    vector<int> nums = {2,1};
    int k = 2;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }
    cout << endl;
    cout << "k = " << k << endl;

    Solution1 P;

    cout << P.findKthLargest(nums, k) << endl;

    return 0;
}