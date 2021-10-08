/*************************************
 * 派生类----C++
 * **********************************/
#include <iostream>
#include <string>

using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
            bookNo(book), price(sales_price) {}
    string isbn() const{return bookNo;}      //返回书编号
    virtual double net_price(size_t n) const{return n*price;}     //返回书实际销售价格
    virtual ~Quote() = default;     //对析构函数进行动态绑定
    virtual void debug();
private:
    string bookNo;         //书编号
protected:
    double price = 0.0;
};

void Quote::debug()
{
    cout << "bookNo: " << bookNo << endl;
    cout << "price : " << price  << endl;
}

class Bulk_quote : public Quote{    //Bulk_quote 继承了Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const string &, double, size_t, double);

    double net_price(size_t) const override;
    void   debug() override;

private:
    size_t min_qty = 0;        //数量（达到该数量就打折）
    double discount = 0.0;     //折扣
};

Bulk_quote::Bulk_quote(const string &book, double pri, size_t n, double dis) :
    Quote(book,pri), min_qty(n), discount(dis) {};

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= min_qty) //打折
    {
        return cnt*(1-discount) * price;
    }
    else   //不打折
    {
        return cnt * price;
    }
}

void  Bulk_quote::debug()
{
    //cout << "bookNo: " << bookNo << endl;
    //cout << "price : " << price  << endl;
    Quote::debug();
    cout << "min_qty : " << min_qty  << endl;
    cout << "discount: " << discount << endl;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold : " << n << "total due : " << ret << endl;

    return ret;
}

class Disc_quote : public Quote{     //抽象基类（含有纯虚函数的类为抽象基类，我们不能定义一个抽象基类的对象）
public:
    Disc_quote() = default;
    Disc_quote(const string & book, double price, size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) {};
    double net_price(size_t n) const = 0;       //纯虚函数
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

int main() 
{
    Quote item("978-7-121-15535-2", 100);         // 基类对象
    Bulk_quote limited("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    print_total(std::cout, item, 2);
    print_total(std::cout, limited, 2);
    print_total(std::cout, limited, 3);
    // 练习 15.11 测试
    item.debug();
    limited.debug();

    return 0;
}

