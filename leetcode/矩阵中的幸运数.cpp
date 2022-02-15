/***********************************
 * 矩阵中的幸运数----1380
 * ********************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rets;
        for(int i = 0; i < m; ++i){
            int min = 999999, y = -1;
            for(int j = 0; j < n;++j){
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                    y = j;
                }
            }
            int ice = 1;
            for(int j = 0; j < m; ++j){
                if(matrix[i][y] < matrix[j][y]){
                    ice = 0;
                }
            }
            if(ice == 1){
                rets.push_back(matrix[i][y]);
            }
        }
        return rets;
    }
};

int main()
{
    int m, n;
    vector<int> matrix;
    cin >> m >> n;

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int num;
            cin >> num;
            matrix.push_back(num);
        }
    }
    vector<int> rets;
    for(auto i : rets)
    {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}