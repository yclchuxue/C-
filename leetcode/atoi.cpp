#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ret = 0;
        int ice = 1, tag = 0, tag1 = 0;
        cout << s[0] << endl;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' && tag == 0){
                continue;
            }
            if(s[i] == ' ' && tag == 1){
                break;
            }else if(s[i] >= '0' && s[i] <= '9'){
                ret = ret * 10 + s[i] - '0';
                if(ret > (long long)INT_MAX){
                    ret = (long long)INT_MAX;
                    tag1 = 1;
                    break;
                }                
                tag = 1;
            }else if(s[i] == '-' && tag == 0){
                tag = 1;
                ice = -1;
            }else if(s[i] == '+' && tag == 0){
                tag = 1;
            }else if(s[i] < '0' || s[i] > '9'){
                break;
            }
        }

        cout << ret << " " << ice << " " << tag << endl;

        if(ret == (long long)INT_MAX && ice == -1){
            if(tag1) return ret*ice - 1;
            else return ret * ice;
        }

        return ret*ice;     
    }
};




int main() {
    cout << "s = ";
    string str;

    cin >> str;

    Solution P;

    cout << P.myAtoi(str) << endl;
}



/*
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};
*/