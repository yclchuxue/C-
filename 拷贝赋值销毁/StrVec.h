#include <iostream>
#include <cstring>
#include <memory>
#include <utility>

using namespace std;

class StrVec{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}  //构造函数

    StrVec(const StrVec&);                //拷贝构造函数

    StrVec &operator=(const StrVec&);     //拷贝赋值符

    ~StrVec();                //析构函数

    void push_back(const string&);    //拷贝元素

    size_t size() const {return first_free - elements;}   

    size_t capacity() const {return cap - elements;}

    string *begin() const {return elements;}

    string *end() const {return cap;}


    // 新加的代码
    // reserve 预留一部分空间，需要一个辅助函数 void reallocate(size_t)
    void reserve(size_t n) { if (n > capacity()) reallocate(n); }
    void resize(size_t);
    void resize(size_t, const string &);
    // 练习 13.40 —— 新添加的一个构造函数
    StrVec(initializer_list<string>);

private:
    static allocator<string> alloc;     //分配元素

    void chk_n_alloc() {if(size() == capacity()) reallocate();}      //被添加元素的函数所使用（确保有足够空间）
    
    pair<string *, string *> alloc_n_copy(const string *, const string *);     //工具函数，被拷贝构造函数，赋值运算符和析构函数使用

    void free();         //销毁元素并释放内存

    void reallocate();   //获得更多内存并拷贝以有元素

    string * elements;   //指向数组首元素指针
    string * first_free; //指向第一个空闲元素指针
    string * cap;        //指向数组尾元素指针

    // 新加的代码
    void reallocate(size_t);

};