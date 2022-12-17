#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution1 {
public:
    string replaceSpace(string s) {
        string rets;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                string ret(1, s[i]);
                rets.append(ret);
            }else{
                rets.append("%20");
            }
        }
        return rets;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        string rets;
        for(auto it : s){
            if(it != ' '){
                rets.push_back(it);
            }else{
                rets.push_back('%');
                rets.push_back('2');
                rets.push_back('0');
            }
        }
        return rets;
    }
};