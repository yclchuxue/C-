#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
        int compare(const string &v1, const string &v2)
        {
            if(v1 < v2) return -1;
            if(v1 > v2) return  1;
            return 0;
        }

        int compare(const double &v1, const double &v2)
        {
            if(v1 < v2) return -1;
            if(v1 > v2) return  1;
            return 0;
        }
};


int main()
{
    Solution S;
    string strs_1 = "ajlkvnkld";
    string strs_2 = "labddljadb";

    double val_1 = 13.3, val_2 = 13.3;

    cout << S.compare(strs_1, strs_2) << endl;
    cout << S.compare(val_1, val_2)   << endl;

    return 0;
}