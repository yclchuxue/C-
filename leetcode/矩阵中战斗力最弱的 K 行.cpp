/***************************************
 * 矩阵中战斗力最弱的 K 行 1337
 * ************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(mat[j][i] == 0)
                {
                    if(i == 0 || mat[j][i-1] != 0)
                    {
                        ret.push_back(j);
                        if(ret.size() == k)
                        {
                            return ret;
                        }
                    }
                }
            }
            if(i == n-1 && ret.size() != k)
            {
                for(int j = 0; j < m; ++j)
                {
                    if(mat[j][i] == 1)
                    {
                        ret.push_back(j);
                        if(ret.size() == k)
                        {
                            return ret;
                        }
                    }
                }
            }
        }
        if(ret.size() != k)
        {
            for(int i = ret.size(); i < k; ++i)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main()
{
    Solution P;
    vector<vector<int>> mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };
    int k = 3;
    vector<int> ret(P.kWeakestRows(mat, k));
    for(int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }

}