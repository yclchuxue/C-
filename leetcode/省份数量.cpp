#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& indexs, int i){
        for(int j = 0; j < isConnected.size(); ++j){
            if(isConnected[i][j] == 1 && !indexs[j]){
                indexs[j] = 1;
                dfs(isConnected, indexs, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<int> indexs(len);
        int ret = 0;

        for(int i = 0; i < len; ++i){
            if(!indexs[i]){
                indexs[i] = 1;
                dfs(isConnected, indexs, i);
                ret++;
            }
        }
        return ret;
    }
};