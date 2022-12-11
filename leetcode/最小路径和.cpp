#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    auto count = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
    int num = 0;
    int rows = grid.size(), cou = grid[0].size();
    for (int i = 0, j = 0; i < rows; i++) {
      num += grid[i][j];
      count[i][j] = num;
    }
    num = grid[0][0];
    for (int i = 0, j = 1; j < cou; j++) {
      num += grid[i][j];
      count[i][j] = num;
    }

    for (int i = 1; i < rows;i++) {
      for (int j = 1; j < cou; j++) {
        if(count[i-1][j] < count[i][j-1]){
            count[i][j] = count[i-1][j] + grid[i][j];
        }else{
            count[i][j] = count[i][j-1] + grid[i][j];
        }
      }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cou; j++){
            cout << count[i][j] << "\t";
        }
        cout << endl;
    }

    return count[rows-1][cou-1];
  }
};

// [1,3,1]
// [1,5,1]
// [4,2,1]

// 1	4	5	
// 2	9	10	
// 6	11	12	
