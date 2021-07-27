#include <iostream>
#include <cstring>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    int a;
    vector<int> values;
    string str;
    vector<string> words;

    while(cin >> a)
    {
        if(a == -1)
        {
            break;
        }
        values.push_back(a);
    }

    while(getline(cin, str))
    {
        if(str == "-1")
        {
            break;
        }
        words.push_back(str);
    }

    for(decltype(values.size()) i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
    for(decltype(words.size()) i = 0; i < words.size(); i++)     //3.17
    {
        for(decltype(words[i].size()) j = 0;j < words[i].size();j++)
        {
            words[i][j] = toupper(words[i][j]);    //小写转换为大写
        }
    }
    for(decltype(words.size()) i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}