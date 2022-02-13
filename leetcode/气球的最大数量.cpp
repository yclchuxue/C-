/***************************
 * 气球的最大数量--------1189
 * *************************/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        float nums[5];
        for(auto i : text)
        {
            //cout << i << endl;
            switch (i)
            {
            case 'b':
                ++nums[0];
                break;
            case 'a':
                ++nums[1];
                break;
            case 'l':
                nums[2] += 0.5;
                break;
            case 'o':
                nums[3] += 0.5;
                break;
            case 'n':
                ++nums[4];
                break;
            default:
                break;
            }
        }
        int ret = nums[0];
        for(int i = 1; i < 5; i++)
        {
            if(ret > nums[i])
            {
                ret = nums[i];
            }
        }

        return ret;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution P;
    cout << P.maxNumberOfBalloons(str) << endl;

    return 0;
}