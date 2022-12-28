#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size(), count;
        if(rows < 0) return 0;
        count = grid[0].size();

        for(int i = 1; i < rows; ++i){
            grid[i][0] = grid[i][0] + grid[i-1][0];
        }

        for(int j = 1; j < count; ++j){
            grid[0][j] = grid[0][j] + grid[0][j-1];
        }

        for(int i = 1; i < rows; ++i){
            for(int j = 1; j < count; ++j){
                grid[i][j] = max(grid[i][j] + grid[i][j-1], grid[i][j] + grid[i-1][j]);
            }
        }

        return grid[rows-1][count-1];
    }
};