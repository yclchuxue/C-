/**********************
 * 测试new
 * *******************/
#include <iostream>
#include <string>
#include <memory>

using namespace std;

void print(shared_ptr<int> p)
{
    cout << *p << endl;
}

int main()
{
    shared_ptr<int> p(new int(42));

    //print(shared_ptr<int>(p));
    print(p);

    cout << *p << endl;

    return 0; 
}