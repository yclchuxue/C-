#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> nums;

        int num = 0, ma = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                nums.push_back(1);
            }else if(s[i] == ')'){
                nums.push_back(1);
                int j = i-1;
                while(1){
                    if(j < 0){
                        break;
                    }
                    if(s[j] == '(' && nums[j] == 1){
                        nums[i] = 0;
                        nums[j] = 0;
                        break;
                    }else{
                        j--;
                    }
                }
            }
        }

        for(int i = 0; i < s.length(); i++){
            cout << nums[i] << "\t";
        }
        cout << endl;

        for(int i = 0; i < s.length(); i++){
            if(nums[i] == 0){
                num++;
            }else if(nums[i] == 1){
                ma = max(num, ma);
                num = 0;
            }
        }
        if(num != 0){
            ma = max(num, ma);         
        }
        

        return ma;
    }
};

int main(){
    Solution P;

    string strs = "()((())";

    cout << "return : " << P.longestValidParentheses(strs);

    return 0;
}