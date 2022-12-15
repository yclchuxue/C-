#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ret;
        do{
            int row = rand7();
            int con = rand7();
            ret = con + (row-1)*7;
        }while(ret > 40);
        return 1+ret%10;
    }
};