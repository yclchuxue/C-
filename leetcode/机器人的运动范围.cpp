#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int getcount(int num){
        int ret = 0;
        while(num != 0){
            ret += num % 10;
            num = num / 10;
        }

        return ret;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> Q;
        int rows[2] = {0, 1};
        int cous[2] = {1, 0};

        int ret = 1;
        Q.push(make_pair(0, 0));

        while(!Q.empty()){
            auto [x, y] = Q.front();
            Q.pop();

            for(int index = 0; index < 2; ++index){
                int tx = rows[index] + x;
                int ty = cous[index] + y;

                if(tx < 0 || tx >= m || ty < 0 || ty >= n || getcount(tx) + getcount(ty) > k || vis[tx][ty]){
                    continue;
                }
                vis[tx][ty] = 1;
                ++ret;
                Q.push(make_pair(tx, ty));
            }
        }

        return ret;
    }
};