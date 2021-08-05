/***********************************
 * 单词搜索-----------79
 * ********************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<char>>& sign,int i, int j, string word,int k)
    {
        int m = board.size(), n = board[0].size();
        //cout << "i = " << i << " j = " << j << " k = " << k << endl;
        //cout << "word = " << word[k] << "\t" << "board = " << board[i][j] << endl;
        if(board[i][j] != word[k])
        {
            return false;
        }
        ++k;
        if(k == word.length()) return true;
        sign[i][j] = '0';
        vector<pair<int,int>> its = {{0,1},{0,-1},{1,0},{-1,0}};
        for(pair<int,int> & it : its)
        {
            int new_i = it.first + i, new_j = it.second + j;
            if(new_i >=0 && new_i < m && new_j >=0 && new_j < n)
            {
                if(sign[new_i][new_j] != '0')
                {
                    //cout << "new_i = " << new_i << " new_j = " << new_j << " k = " << k << endl;
                    //cout << "B" << "\t" << k << endl;
                    if(check(board, sign,new_i, new_j, word, k)) return true;
                    else sign[new_i][new_j] = board[new_i][new_j];
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                vector<vector<char>> sign = board;
                //cout << i << " " << j << endl;
                if(check(board, sign,i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    /*
    vector<vector<char>> board = { 
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    */
    //*
    vector<vector<char>> board = { 
            {'C', 'A', 'A'},
            {'A', 'A', 'A'},
            {'B', 'C', 'D'}
    };
    string word = "AAB";
    //*/
    /*
    vector<vector<char>> board = { 
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCESEEEFS";
    */
    Solution P;
    bool ret = P.exist(board, word);

    cout << ret << endl;

    return 0;
}