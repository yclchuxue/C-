#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> counts(nums);
        int size = nums.size(), ret = -1;
        sort(counts.begin(), counts.end());
        for(int i = 0; i < size; i++){
            if(nums[i] == counts[size-1]){
                ret = i;
            }
        }
        return ret;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();

        int left = 0, right = size-1;
        while(left < right){
            int mid = (right - left)/2 + left;
            cout << "mid = " << mid << " left = " << left << " right = " << right << endl;
            if(mid == left){
                if(mid + 1 <= right){
                    if(nums[mid] > nums[mid + 1]) {
                        return mid;
                    }else{
                        left++;
                    }
                }else{
                    return mid;
                }
            }else if(mid == right){
                if(mid - 1 >= left){
                    if(nums[mid] > nums[mid-1]){
                        return mid;
                    }else{
                        right--;
                    }
                }else{
                    return mid;
                }
            }else{
                bool le = false, ri = false;
                if(nums[mid-1] < nums[mid]){
                    le = true;
                    left++;
                }
                if(nums[mid+1] < nums[mid]){
                    ri = true;
                    right--;
                }
                if(le && ri){
                    return mid;
                }
                if(!le && !ri){
                    right--;
                }
            }
        }
        return left;
    }
};

int main(){
    vector<int> nums{3,1,2};

    Solution P;

    cout << P.findPeakElement(nums) << endl;

    return 0;
}