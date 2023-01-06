#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//         reverse(s.begin(), s.end());

//         int len = s.size();
//         int start = 0, end = 0;
//         bool ice = false;

//         while (s[end] == ' ') {
//             end++;
//         }

//         start = end;
//         s = s[start];

//         for(; start <= end && end < len; ++end){
//             if(s[end] == ' '){
//                 if(ice){
//                     cout << start << "\t" << end << endl;
//                     reverse(s.begin() + start, s.begin() + end);
//                     cout << s << endl;
//                     ice = false;
//                 }
//                 int index = end+1;
//                 while (index < len && s[index] == ' ') {
//                     index++;
//                 }
//                 start = index;
//                 end = index;
//             }else{
//                 ice = true;
//             }
//         }
//         if(ice){
//             reverse(s.begin() + start, s.end());
//         }
//         return s;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                cout << start << "\t" << end << "\t" << idx << endl;
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
 

int main(){
    string s = "  the sb ti ";

    Solution P;

    cout << P.reverseWords(s) << endl;
}