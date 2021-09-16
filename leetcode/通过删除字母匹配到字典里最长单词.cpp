/***************************************
 * 通过删除字母匹配到字典里最长单词------524
 * ************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        //vector<string> rets;
        string max_s;
        int max = 0;
        for(auto strs : dictionary)
        {
            int i = 0, num = 0;
            
            for(int j = 0; j < s.length(); ++j)
            {
                if(strs[i] == s[j])
                {
                    ++num;
                    ++i;
                }
            }
            if(i == strs.length())
            {
                if(num > max)
                {
                    max = num;
                    max_s = strs;
                }
                if(num == max)
                {
                    if(max_s > strs) max_s = strs; 
                }
                //rets.push_back(strs);
            }
        }
        /*
        for(auto i : rets)
        {
            cout << i << "\t";
        }
        */
        return max_s;
    }
};

int main()
{
    string s, strs;
    vector<string> dictionary;
    Solution S;
    cin >> s;
    while(cin >> strs)                //EOF结束输入
    {
        dictionary.push_back(strs);
    }

    string rets = S.findLongestWord(s, dictionary);

    cout << rets << endl;
/*
    cout << s  << endl;
    for(auto i : dictionary)
    {
        cout << i << "\t";
    }
*/
    return 0;
}