#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int count = 0;
        if(row > 0) count = matrix[0].size();
        int x = 0, y = 0;
        bool ice = false;
        cout << row << " " << count << endl;
        for(; x < row && y < count && x >= 0 && y >= 0; ){
            cout <<matrix[x][y] << " ";
            if(matrix[x][y] < target){
                if(y + 1 < count){
                    if(!ice){
                        y++;
                    }else{
                        x++;
                    }
                }else{
                    x++;
                    ice = true;
                }
            }else if(matrix[x][y] == target){
                return true;
            }else if(matrix[x][y] > target){
                if(ice){
                    y--;
                }else{
                    y--;
                    x++;
                    ice = true;
                }
            }
            cout << x << " " << y << endl;
        }   
        return false;
    }
};

int main(){

}