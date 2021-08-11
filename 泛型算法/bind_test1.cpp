#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using placeholders::_1;


void output_words(vector<string> &words) 
{
    // 打印容器中的内容，方便观察程序执行状态
    for (auto &s : words)
        std::cout << s << " ";
    cout << words.size() << endl;
}

bool check_size(const string &s, string::size_type sz) 
{
    return s.size() <= sz;
}

// 如果 ctr 的值大于 1，返回 word 的复数形式
string make_plural(size_t ctr, const string &word,
                   const string &ending) 
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) 
{
    output_words(words);

    // 统计满足 size() <= sz 的元素的个数
    auto count = count_if(words.begin(), words.end(), bind(check_size, _1, 6));
                                            //count_if将迭代器范围内的元素依次带入_1中传递给chek_size
    output_words(words);
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or smaller" << endl;
}

int main() 
{
    std::vector<std::string> svec = {"determined", "quick", "nuclear", "fox",
                                     "negotiations", "Things", "accelerating"};
    biggies(svec, 6);
    return 0;
}