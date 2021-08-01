#include <iostream>
#include<string>
#include<vector>
using namespace std;
struct Sales_data {
	Sales_data();
	string bookNo;
	unsigned units_sold ;
	double revenue ;//类内部的变量成员不允许在定义时初始化，必须使用构造函数
};
Sales_data::Sales_data()
{
	units_sold = 0;
	revenue = 0.0;     //收益
}
 
int main(int argc, char **argv)
{
	Sales_data total;//此部分和第一章21页的内容相同
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) 
    {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) 
        {
			if (total.bookNo == trans.bookNo) 
            {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;//第三题的使用修改之处
			}
			else 
            {
				cout << total.bookNo << " " << total.units_sold << " "
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue
			<< endl;
	}
	else 
    {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}