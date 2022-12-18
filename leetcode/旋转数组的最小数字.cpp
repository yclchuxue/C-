#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        int left = 0, right = len-1;
        while(left < right){
            int bot = (right-left)/2 + left;
            if(numbers[bot] < numbers[right]){
                right = bot;
            }else if(numbers[bot] > numbers[right]){
                left = bot+1;
            }else{
                right -= 1;
            }
        }

        return numbers[left];
    }
};

int main(){
    vector<int> nums = {1,1};

    Solution P;
    
    cout << P.minArray(nums) << endl;
}