#include <deque>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    deque<int> de;
public:
    string reverseLeftWords(string s, int n) {
        int len = s.length();
        string rets;
        for(int i = 0; i < len; i++){
            if(i < n){
                de.push_back(s[i]);
            }else{
                rets.push_back(s[i]);
            }
        }

        while(!de.empty()){
            rets.push_back(de.front());
            de.pop_front();
        }

        return rets;
    }
};