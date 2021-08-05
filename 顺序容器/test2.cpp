/*****************************
 * 测试vector容量是如何增长的---成倍数增长
 * **************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    int value;
    while(cin >> value)
    {
        if(value == -1)
        {
            break;
        }
        nums.push_back(value);
        cout << "size = " << nums.size() << "\t" << "capacity = " << nums.capacity() << endl;
    }

    return 0;
}