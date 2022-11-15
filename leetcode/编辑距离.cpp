#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int D[len1+1][len2+1];

        D[0][0] = 0;
        for(int i = 1; i <= len1; i++){
            D[i][0] = i;
        }
        for(int j = 1; j <= len2; j++){
            D[0][j] = j;
        }

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                int x = min(D[i-1][j], D[i][j-1]);
                if(word1[i-1] == word2[j-1]){
                    x = min(x, D[i-1][j-1]-1);
                }else{
                    x = min(x, D[i-1][j-1]);
                }
                // cout << word1[i] << " " << word2[j] << endl;
                // cout << i << " " << j << " " << x << endl;
                D[i][j] = x+1;
            }
        }

        // for(int i = 0; i <= len1; i++){
        //     for(int j = 0; j <= len2; j++){
        //         cout << D[i][j] << "\t";
        //     }
        //     cout << endl;
        // }

        return D[len1][len2];
    }
};

    //          r   o   s
    //     0	1	2	3	
    // h   1	0	1	2	
    // o   2	1	1	2	
    // r   3	2	1	2	
    // s   4	3	2	2	
    // e   5	4	3	2	

int main(){
    string w1 = "horse", w2 = "ros";

    Solution P;

    P.minDistance(w1,w2);
}