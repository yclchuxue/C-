#ifndef TEST_STRBLOB_H
#define TEST_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using std::string;
using std::vector;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;

class StrBlob 
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    // 元素访问
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    // 如果 data[i] 不合法，抛出一个异常
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list <string> il) :
                data(make_shared<vector<string>>(il)) { }

void StrBlob::check(vector<string>::size_type i, const string &msg) const 
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front() 
{
    // 如果 vector 为空，check 会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

// const 版本 front
const string& StrBlob::front() const 
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() 
{
    check(0, "back on empty StrBlob");
    return data->back();
}

// const 版本 back
const string& StrBlob::back() const 
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() 
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

#endif //TEST_STRBLOB_H