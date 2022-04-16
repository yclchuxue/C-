#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {

    public:

    bool isUnique(string astr){

        int ch[26] = {0};

        for(auto iter = astr.begin() ; iter != astr.end(); iter++){
            int i = *iter - 'a';

            ch[i]++;

            if(ch[i] >= 2){
                return  false;
            }
        }

        return true;
    }
};  

int main()
{
    string astr;

    cin >> astr;

    Solution P;

    cout << P.isUnique(astr) << endl;

    return 0;
}