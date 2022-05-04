#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;

        int len1 = num1.length(), len2 = num2.length();
        int i = len1 - 1, j = len2 - 1, flag = 0;
        for(; i >= 0 && j >= 0; i--, j--){
            int x = num1[i] - '0';
            int y = num2[j] - '0';
            int sum = x + y;
            string s;

            if(sum >= 10){
                sum = sum - 10;
                s = '0' + sum;
                ret = "1" + s;
            }else{
                flag = 0;
            }
        }

        return ret;
    }   
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    string num1 = "123";
    string num2 = "11";

    Solution P;

    int sum = 15 - 10;
    string s = '0' + sum;
    string ret = "1" + s;

    //cout << P.addStrings(num1, num2) << endl;

    cout << num1[0] << endl;
    printf("%d", num1[0]);

    return 0;
}