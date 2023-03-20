#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stacks;

        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                stacks.push(ch);
            }else{
                if(!stacks.empty()){
                    char str = stacks.top();
                    stacks.pop();
                    cout << ch << "\t" << str << endl;
                    if(str == '(' && ch != ')'){
                        return false;
                    }else if(str == '{' && ch != '}'){
                        return false;
                    }else if(str == '[' && ch != ']'){
                        return false;
                    }

                }else{
                    return false;
                }
            }
        }

        if(stacks.empty())  return true;
        else                return false;
    }
};