#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string getstring(vector<string> str){
        string rets;
        for(auto it = str.begin(); it != str.end(); it++){
            rets += *it;
        }
        return rets;
    }

    string getDigits(string &s, int &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string decodeString(string s) {
        int s_size = s.size(), num = 0, nums = 0;
        string str1 = "";
        vector<string> stk;

        for(int i = 0; i < s_size; ++i){
            if (isdigit(s[i])) {
                // 获取一个数字并进栈
                string digits = getDigits(s, i);
                stk.push_back(digits);
            }
            if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z') || s[i] == '['){
                stk.push_back(string(1, s[i]));
            }else{
                vector<string> sub;
                while(stk.back() != "["){
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();
                int n = stoi(stk.back());
                stk.pop_back();
                string str3, str4 = getstring(sub);
                while(n) {
                    n--;
                    str3 += str4;
                }
                stk.push_back(str3);
            }

        }

        return getstring(stk);
    }
};

int main(){
    string s = "3[a]2[bc]";

    Solution P;

    cout << P.decodeString(s) << endl;

    return 0;
}