#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>//标准异常库
using namespace std;
int main()
{	
	int a,b;
	cout<<"请输入相除的两个整数：";
	while(cin>>a>>b)
	{
		try
		{
			if (b == 0) throw std::runtime_error("被除数不能为0");//runtime_error异常类:只有在运行时才能检测出的问题
			cout<<static_cast<double>(a)/b<<endl;//考虑到不可以整除产生小数的情况,先将a强制转化为double类型
		}
		catch (runtime_error err)//err是runtime_error类的一个实例
		{
			cout << err.what() ;//实例的成员函数，返回内容由编译其决定
			cout << "\n是否需要重新输入? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;//break只能用在开关体或者循环体中
		}//简单来说try是检测异常的，如果产生了异常，就throw(抛出)一个异常，然后被catch到，进行异常的处理
		//如果没有catch部分，仅有try，仍然会报错
	}
}