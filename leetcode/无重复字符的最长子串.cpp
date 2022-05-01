#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();

        unordered_set<char> occ;

        int ret = 0;

        for(int i = 0; i < len; ++i){

            occ.insert(s[i]);

            int j = i+1, nums = 1;

            while(j < len && occ.count(s[j]) == 0){
                nums++;
                occ.insert(s[j]);
                ++j;
            }
            
            occ.clear();
            ret = max(nums, ret);
        }

        return ret;
    }
};

int main(){
    string strs = "dvdf";

    Solution P;

    cout << P.lengthOfLongestSubstring(strs) << endl;

    return 0;
}