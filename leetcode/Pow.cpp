/*****************************
 * leetcode------Pow(x,n)--50
 * **************************/
#include <iostream>

using namespace std;

class Solution {
public:
    double my_pow(double ret, double x, int n)
    {
        if(n == 2)
        {
            return ret*ret;
        }
        if(n%2 == 0)
        {
            ret = my_pow(ret, x, n/2);
            return ret*ret;
        }
        if(n%2 == 1)
        {
            ret = my_pow(ret, x, (n-1)/2);
            ret = ret * x;
            return ret;
        }

        return ret;
    }

    double myPow(double x, int n) 
    {
        double ret = x;
        int k = 1, m = 0;
        if(x == 0)  return 0;
        if(n == 0)  return 1;
        if(n == 1)  return x;
        if(n == -1) return 1.0/x;
        if(n < 0)   
        {
            k = -1;
            n = -1*n;
        }

        ret = my_pow(ret, x, n);

        return ret;
    }
};

int main()
{
    double num = 2;
    int n = 14;
    Solution S;
    double ret = S.myPow(num, n);

    cout << ret << endl;

    return 0;
}