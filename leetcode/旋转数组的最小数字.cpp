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
            cout << numbers[left] << "\t" << numbers[bot] << "\t"<< numbers[right] << endl;
            if(numbers[left] < numbers[bot]){
                if(numbers[bot] < numbers[right]){
                    right = bot-1;
                }else if(numbers[bot] == numbers[right]){
                    right = bot - 1;
                }else if(numbers[bot] > numbers[right]) {
                    left = bot + 1;
                }
            }else if(numbers[left] == numbers[bot]){
                if(numbers[bot] < numbers[right]){
                    if(bot != left) {
                        right = bot - 1;
                    }else{
                        right = bot;
                    }
                }else if(numbers[bot] == numbers[right]){
                    left++;
                    right--;
                }else if(numbers[bot] > numbers[right]) {
                    if(bot != right){
                        left = bot + 1;
                    }else{
                        left = bot;
                    }
                }
            }else if(numbers[left] > numbers[bot]) {
                if(numbers[bot] < numbers[right]){  
                    if(numbers[bot-1] < numbers[right] && numbers[bot-1] < numbers[left]) {
                        right = bot - 1;
                    }else{
                        right = bot;
                    }
                }else if(numbers[bot] == numbers[right]){
                    right = bot;
                }
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