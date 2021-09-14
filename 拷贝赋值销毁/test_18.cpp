/**********************************
 * C++ primer---拷贝赋值销毁---18题
 * *******************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee{
private:
    static int sn;
public:
    Employee() {id = sn++;}    //构造函数
    Employee(const string &s) : name(s), id(sn++) {}    //构造函数
    const string &get_name() {return name;}
    int get_id() {return id;}
    Employee(const Employee &e) : name(e.name), id(e.sn++) {}    //拷贝构造函数
    Employee &operator=(Employee &rhs)                       //拷贝赋值函数
    {
        name = rhs.name;
        return *this;
    }
private:
    string name;
    int id;
};

int Employee::sn = 0;

