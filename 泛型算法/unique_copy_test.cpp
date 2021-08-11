#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> ivec{1, 2, 2, 3, 4, 5, 5, 6};
    list<int> ilst;

    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));

    for (auto v : ilst)
        cout << v << " ";
    
    cout << endl;

    return 0;
}