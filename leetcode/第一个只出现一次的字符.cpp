#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> strmap;
        queue<char>  de;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(!strmap.count(s[i])){
                strmap[s[i]] = 1;
                de.emplace(s[i]);
            }else{
                strmap[s[i]] = -1;
                while(!de.empty() && strmap[de.front()] == -1){
                    de.pop();
                }
            }
        }
        if(!de.empty()) return de.front();
        else            return ' ';
    }
};