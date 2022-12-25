#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> occ;  
        int len = s.size(), ret = 0, i;
        if(len < 2) return len;
        int left = 0;
        occ[s[0]] = 0;
        for(i = 1; i < len; ++i){
            if(!occ.count(s[i])){
                occ[s[i]] = i;
            }else{
                cout << left << " " << i << endl;
                ret = max(i-left, ret);
                if(left <= occ[s[i]]) left = occ[s[i]] + 1;
                if(i < left) i = left;
                occ[s[i]] = i;
            }
        }

        ret = max(i-left, ret);

        return ret;
    }
};