#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int left, right, top, down, tag, m, n;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rets;
        
        tag   = 1;
        left  = 0;
        top   = 1;
        m = matrix.size();
        down = m - 1;
        if(m == 1){ return vector<int>(matrix[0]); }
        if(m > 1) { 
            n = matrix[0].size(); 
            right = n - 1;
        }

        int i = 0, j = 0;
        while(1){
            if(rets.size() == m*n){
                break;
            }

            if(tag == 1){
                if(j > right){
                    ++tag;
                    j--;
                    i++;
                    right--;
                }else{
                    rets.push_back(matrix[i][j]);
                    ++j;
                }
            }else if(tag == 2){
                if(i > down){
                    ++tag;
                    i--;
                    j--;
                    down--;
                }else{
                    rets.push_back(matrix[i][j]);
                    i++;
                }
            }else if(tag == 3){
                if(j < left){
                    ++tag;
                    ++j;
                    i--;
                    left++;
                }else{
                    rets.push_back(matrix[i][j]);
                    j--;
                }
            }else if(tag == 4){
                if(i < top){
                    tag = 1;
                    i++;
                    j++;
                    top++;
                }else{
                    rets.push_back(matrix[i][j]);
                    i--;
                }
            }
        }
        return rets;
    }
};