/*******************************
 * 306.累加数
 * 使用了回溯，但需要考虑到数据可能会溢出
 * ****************************/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long double>tmp;
        return dfs(num,tmp);
    }
    bool dfs(string num,vector<long double> tmp){       //深度优先搜索
        int n = tmp.size();
        if(n>=3 && tmp[n-1] != tmp[n-2]+tmp[n-3]) return false;
        if(num.size()==0 && n>=3) return true;
        for(int i = 0;i<num.size();++i){
            string cur = num.substr(0,i+1);
            if(cur[0]=='0' && cur.size()!=1) continue;
            tmp.push_back(stold(cur));
            if(dfs(num.substr(i+1),tmp)) return true;
            tmp.pop_back();
        }
        return false;
    }
};

int main()
{
    string num;
    Solution P;
    
    cin >> num;

    cout << P.isAdditiveNumber(num) << endl;

    return 0;
}
