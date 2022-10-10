#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    string getstring(string &s, int &i){
        int num = s.size();
        string ret = "";
        for(; i < num; ++i){
            if(s[i] != ' '){
                ret += string(1, s[i]);
            }else{
                break;
            }
        }
        return ret;
    }

    string reverseWords(string s) {
        vector<string> sub;
        int num = s.size(), nums = 0;
    
        for(int i = 0; i < num; ++i){
            if(s[i] != ' '){
                string str = getstring(s, i);
                sub.push_back(str);
                nums++;
            }
        }

        int j = 0;
        string ret = "";
        for(int i = nums-1; i >= 0; i--){
            ret += sub[i];
            j++;
            if(j != nums){
                ret += " ";
            }
        }

        return ret;
    }
};

int main(){
    string s = "the sky is blue";

    Solution P;

    cout << P.reverseWords(s) << endl;
}