/**************************************
 * 找出星型图的中心节点--------1791
 * ***********************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degrees(n + 1);
        for (auto & edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        for (int i = 1; ; i++) {
            if (degrees[i] == n - 1) {
                return i;
            }
        }
    }
};

 

int main()
{
    vector<vector<int>> nums;

}