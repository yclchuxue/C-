#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};


class Solution1{
private:
    int num;
    int dfs(vector<vector<char>>& grid, int i, int j) {
        cout << "grid[" << i << "][" << j << "]" << endl;
        if(grid[i][j] == '0' || grid[i][j] == '2'){
            cout << grid[i][j] << "over"<< endl;
            return 0;
        }else{
            cout << "\t\t\tgrid[" << i << "][" << j << "] = " << grid[i][j] << endl;
            grid[i][j] = '2';
        }

        if(i-1 >= 0)                dfs(grid, i-1, j);
        if(i+1 < grid.size())       dfs(grid, i+1, j);
        if(j-1 >= 0)                dfs(grid, i, j-1);
        if(j+1 < grid[i].size())    dfs(grid, i, j+1);

        return 1;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int ret = dfs(grid, i, j);
                if(ret == 1){
                    num++;
                    cout << "num++" << endl;
                }
            }
        }

        return num;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };

    Solution1 P;

    cout << P.numIslands(grid) << endl;
}