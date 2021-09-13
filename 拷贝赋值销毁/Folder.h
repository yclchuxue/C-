#include <iostream>
#include <set>

using namespace std;

class Folder;

class Message{
    friend void swap(Message&, Message&);
    friend class Folder;

public:
    explicit Message(const string &str = "") : contents(str) {}      //构造函数

    Message(const Message&);            //拷贝构造函数

    Message& operator=(const Message&); //拷贝赋值符

    ~Message();                         //析构函数

    void save(Folder&);

    void remove(Folder&);

    void debug_print();

private:
    string contents;           //消息文本

    set<Folder*> folders;      //包含本Message的所有Folder

    void add_to_Folders(const Message&);           //从本Message添加到指向参数的Folder

    void remove_from_Folders();                    //从folders中的每个Folder中删除Message

    void addFldr(Folder *f) { folders.insert(f); }

    void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);        //交换

class Folder {
    friend void swap(Message&, Message&);
    friend class Message;

public:
    ~Folder();                              //析构函数
    Folder(const Folder&);                  //拷贝构造函数
    Folder& operator=(const Folder&);       //拷贝赋值符

    Folder() { }                            //构造函数

    void save(Message&);                    //向Folder中添加一个Message
    void remove(Message&);                  //从Folder中删除一个Message

    void debug_print();                     // print contents and it's list of Folders

private:
    set<Message*> msgs;                     //该Folder中所有的Message

    void add_to_Messages(const Folder&);    // add this Folder to each Message
    void remove_from_Msgs();                // remove this Folder from each Message
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};