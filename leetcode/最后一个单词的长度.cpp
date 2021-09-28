/*********************************
 * 最后一个单词的长度---leetcode--58
 * ******************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0, num = 0, q_num = 0;
        //cout << s.length() << endl;
        for(;i < s.length(); ++i){
            if(i == 0 && s[i] != ' '){
                num = 1;
            }else if(s[i] == ' '){
                if(num != 0)
                    q_num = num;
                num = 0;
            }else{
                ++num;
            }
            //cout << s[i] <<" "<< num << " " << q_num << endl;
        }
        if(num) return num;
        else    return q_num; 
    }
};

int main()
{
    string s = "   fly me   to   the moon  ";

    Solution S;
    cout << S.lengthOfLastWord(s) << endl;

    return 0;
}

/*
cout输出2位的书即%2d
*/