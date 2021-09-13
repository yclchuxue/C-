#include "Folder.h"

int main() 
{
    Message firstMail("hello");
    Message signInMail("welcome to cpp primer");
    Message mail;
    Folder mailBox;

    firstMail.debug_print();        // print: "hello"
    firstMail.save(mailBox);        // send to mailBox
    mailBox.debug_print();          // print: "hello"

    signInMail.debug_print();       // print "welcome to cppprimer"
    signInMail.save(mailBox);       // send to mailBox
    mailBox.debug_print();          // print "welcome to cppprimer hello"

cout << "AAAAAAAAAAA" << endl;

    firstMail = firstMail;          // test for assignment to self
    firstMail.debug_print();        // print "hello"
    mailBox.debug_print();          // print "welcome to cppprimer hello"

cout << "BBBBBBBBBBB" << endl;

    mail = firstMail;
    mail.debug_print();
    mailBox.debug_print();
    return 0;
}