#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
using namespace std;
class Sales_data
{    //友元
	friend Sales_data add(const Sales_data& lns, const Sales_data& rhs);
	friend istream& read(istream& is, Sales_data& item);
	friend ostream& print(ostream& os, const Sales_data& item);
public:
	//构造函数
	Sales_data() = default;
	Sales_data(const string& s) :bookNo(s) {};
	Sales_data(const string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n* p) {};
	Sales_data(istream& is);
	//成员函数
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};     //类的非成员接口函数声明（本编译器非强制）
Sales_data add(const Sales_data& lns, const Sales_data& rhs);
istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
//各函数定义
istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
Sales_data add(const Sales_data& lns, const Sales_data& rhs)
{
	Sales_data sum = lns;
	sum.combine(rhs);
	return sum;
}
ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
 
inline double Sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data::Sales_data(istream& is)
{
	read(is, *this);   //由输入初始化该类对象  调用read函数是对该类写值
}
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
#endif // !SALES_DATA_H