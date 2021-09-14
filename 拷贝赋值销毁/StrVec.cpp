#include "StrVec.h"

void StrVec::push_back(const string &s)
{
    chk_n_alloc();         //确保有空间容纳新元素

    alloc.construct(first_free++, s);    //将新元素s加入数组中
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e-b);      //分配足够内存空间

    return {data, uninitialized_copy(b, e, data)}; //使用uninitialized_copy将迭代器范围内的元素拷贝至未构造的原始内存中
}

void StrVec::free()
{
    if(elements) 
    {
        for(auto p = first_free; p != elements; )       //逆序销毁
        {
            alloc.destroy(--p);     //对指针所指的对象进行析构函数
        }
        alloc.deallocate(elements, cap - elements);    //释放elements后的一定数量内存，调用前必须对内存中的对象使用destroy
    }
}

StrVec::StrVec(const StrVec &s)      //拷贝构造函数
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }        //Strvec析构函数

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();       //释放已有元素
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;   //分配当前大小的2倍的内存

    auto newdata = alloc.allocate(newcapacity);   //分配一段原始的未构造的内存，能储存newcapacity个string

    auto dest = newdata;    //指向新数组中下一个空闲位置

    auto elem = elements;   //指向旧数组中下一个元素

    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, move(*elem++));
    }
    free;
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

// 新加的代码，StrVec::reallocate() 函数的重载形式
void StrVec::reallocate(size_t newcapacity) {
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);

    // 将数据从旧空间移动到新空间
    auto dest = newdata;            // dest 指向新空间中第一个空闲位置
    auto elem = elements;           // 指向旧空间中下一个元素
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();                         // 数据移动完毕，释放旧空间

    // 更新指针，指向新空间开始、第一个空闲位置及末尾位置
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t count) {
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s) {
    if (count > size()) {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

StrVec::StrVec(initializer_list<string> il) {
    // 调用 alloc_n_copy 分配与列表 il 中元素数目一样多的空间
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
