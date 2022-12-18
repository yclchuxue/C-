#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<string> rets;

    bool checkip(string strs, int tag){
        switch (tag) {
            case 1:
                
                if(strs[0] == '0'){
                    bool ret = checkip(&strs[1], 1);
                }else{
                    for(int i = 0; i < 3; i++){
                        
                    }
                }
                break;
            case 2:
                if(strs[0] == '0'){
                    bool ret = checkip(&strs[1], 1);
                }else{
                    for(int i = 0; i < 3; i++){
                        
                    }
                }
                break;
            case 3:
                if(strs[0] == '0'){
                    bool ret = checkip(&strs[1], 1);
                }else{
                    for(int i = 0; i < 3; i++){
                        
                    }
                }
                break;
            case 4:
                if(strs[0] == '0'){
                    bool ret = checkip(&strs[1], 1);
                }else{
                    for(int i = 0; i < 3; i++){
                        
                    }
                }
                break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        checkip(s, 1);
        return rets;
    }
};