#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person
{
public://声明为public
	Person(string Client_name, string Client_address);//构造函数
	Person();//构造函数的重载
 
	string name;
	string address;//内部变量

	void Show_info()
	{
		cout<<name<<"'s"<<" address is "<<address<<endl;
	}//类内定义函数
 
	const string &getname()
    {
        return name;
    }
 
    const string &getaddress()
    {
        return address;
	}//返回姓名地址的函数，只可访问，不可修改
};
Person::Person(string Client_name, string Client_address)
{
    name = Client_name;
    address = Client_address;
};
//构造函数定义内部变量
//此处我们在一个文件内定义了该类，如若类较大，应置于.h文件中
int main(int argc, char **argv)
{
	Person Client1("Mr.right","your heart");//实例化
	Client1.Show_info();//调用其中的显示信息函数

    cout << Client1.getname() << endl;
    cout << Client1.getaddress() << endl;

    const string &p = Client1.getname();

    cout << p << endl;

	return 0;
}