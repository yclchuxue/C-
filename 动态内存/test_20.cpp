/********************************
 * C++ primer 20题
 * *****************************/
#include <iostream>
#include <fstream>
#include "strblob.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "请给出文件名" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in) {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }

    StrBlob b;
    string line;
    while (getline(in, line))
        b.push_back(line);
    for (auto iter = b.begin(); neq(iter, b.end()); iter.incr())
        // 打印元素，元素间用换行分割
        cout << iter.deref() << endl;

    return 0;
}