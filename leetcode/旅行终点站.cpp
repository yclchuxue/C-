/********************************
 * leetcode----旅行终点站1436
 * *****************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> uset;
        for(auto& c : paths){
            uset.insert(c[0]);
        }
        string res;
        for(auto& c : paths){
            if(!uset.count(c[1])){     //count在unordered_set中查找键值为c[1]的个数
                res = c[1];
                break;
            }             
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<string>> paths = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
    string strs = S.destCity(paths);

    cout << strs << endl;


    return 0;
}