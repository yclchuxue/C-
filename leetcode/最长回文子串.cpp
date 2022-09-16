#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int begin = 0;
        int maxlen = 1;

        vector<vector<bool>> dp(len, vector<bool>(len));

        for(int i = 0; i < len; i++){
            dp[i][i] = true;
        }

        for(int right = 1; right < len; ++right){
            for(int left = 0; left < right; ++left){
                if(s[left] != s[right]){
                    dp[left][right] = false;
                }else{
                    if(right - left < 3){
                        dp[left][right] = true;
                    }else{
                        dp[left][right] = dp[left+1][right-1];
                    }
                }

                if(maxlen < right - left + 1 && dp[left][right]){
                    maxlen = right-left+1;
                    begin = left;
                }
            }
        }

        return s.substr(begin, maxlen);
    }
};

int main(){
    string strs = "dbabd";

    Solution P;

    cout << P.longestPalindrome(strs);

    return 0;
}