/*******************
 * 测试shared_ptr
 * ****************/
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    int val = 10;
    shared_ptr<int> p(make_shared<int>(val));

    cout << *p << " " << p.use_count() << endl;

    shared_ptr<int> q(make_shared<int>(20));

    cout << *q << " " << q.use_count() << endl;

    q = p;          //q原本的引用计数为1,p原来的引用计数为1,
                    //运行该语句时，p的引用计数加一，q的引用
                    //计数先减一（如果为0,就将原来所指空间的内存释放）
                    //然后q的引用计数等于p的引用计数，为2

    cout << *q << " " << q.use_count() << " " << p.use_count() << endl;

    return 0;
}