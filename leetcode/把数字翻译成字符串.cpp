#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        int p = 0, q = 0, r = 1;

        string str = to_string(num);

        for(int i = 0; i < str.length(); ++i){
            p = q;
            q = r;
            
            if(i == 0){
                continue;
            }
            string x = str.substr(i-1, 2);

            if(x >= "10" && x <= "25"){
                r += p;
            }
        }

        return r;
    }
};