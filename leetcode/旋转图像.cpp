#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//先上下反转，再对角反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) matrix[i].swap(matrix[n - 1 - i]);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};