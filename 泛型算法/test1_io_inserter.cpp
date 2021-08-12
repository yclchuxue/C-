#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() 
{
    // 创建流迭代器从标准输入读入整数
    istream_iterator<int> in_iter(cin);
    // 尾后迭代器
    istream_iterator<int> eof;
    vector<int> ivec;
    while (in_iter != eof)
        ivec.push_back(*in_iter++);     // 存入 vector 并递增迭代器

    sort(ivec.begin(), ivec.end());

    ostream_iterator<int> out_iter(cout, " ");
    copy(ivec.begin(), ivec.end(), out_iter);   //copy到输出流中

    return 0;
}