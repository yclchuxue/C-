/***************************
 最简分数-------1447
 ***************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pb(int m, int n){
        int c, ice = 0;
        while(n%m != 0)
        {   ice = 1;
            c = n%m;
            n = m;
            m = c;
        }
        if(m == 1 && ice == 1)
        {
            return 1;         //无法化简
        }else{
            return 0;
        }
    }

    vector<string> simplifiedFractions(int n) {
        vector<string> strs;
        while(n > 1)
        {
            strs.push_back(to_string(1)+"/"+to_string(n));
            for(int i = 1; i < n; ++i){
                if(pb(i, n)){
                    strs.push_back(to_string(i)+"/"+to_string(n));
                }
            }
            --n;
        }
        return strs;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution P;
    vector<string> strs;
    strs = P.simplifiedFractions(n);

    for(auto str : strs)
    {
        cout << str << "\t";
    }
    cout << endl;

    return 0;
}