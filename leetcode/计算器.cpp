#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool ischar(char sh) {
    // cout << sh << " - '0' is " << sh-'0' << endl;

    if (sh - '0' > 9 || sh - '0' < 0) {
      return true;
    } else {
      return false;
    }
  }

  int getint(string str, int &i) {
    int len = str.size();
    int ret = str[i] - '0';
    for (i = i + 1; i < len; ++i) {
      if (!ischar(str[i])) {
        ret = ret * 10 + (str[i] - '0');
      } else {
        break;
      }
    }

    return ret;
  }

  int solve(string s) {

    stack<int> stk1;
    stack<char> stk2;
    int len = s.size(), i = 0;

    // cout << s[0] - '0' << endl;

    if (len < 1)
      return 0;
    if (len == 1)
      return s[0] - '0';

    if (!ischar(s[0])) {
      int num = getint(s, i);
      cout << "push " << num << endl;
      stk1.push(num);
    } else
      stk2.push(s[0]);

    for (; i < len;) {
      if (ischar(s[i])) {
        if (!stk2.empty()) {
          char k = stk2.top();
          if (k == '(') {
            stk2.push(s[i]);
          } else if ((k == '+' || k == '-') && (s[i] == '*' || s[i] == '(')) {
            stk2.push(s[i]);
          } else if (s[i] == ')') {
            while (k != '(') {
              int num1 = stk1.top();
              stk1.pop();
              int num2 = stk1.top();
              stk1.pop();

              stk2.pop();

              cout << num2 << " " << k << " " << num1 << endl;

              if (k == '*') {
                stk1.push(num1 * num2);
              }
              if (k == '-') {
                stk1.push(num2 - num1);
              }
              if (k == '+') {
                stk1.push(num2 + num1);
              }

              if (stk2.empty()) {
                stk2.push(s[i]);
                break;
              }

              k = stk2.top();

              if (k == '(')
                stk2.pop();
            }

          } else {
            while (1) {
              int num1 = stk1.top();
              stk1.pop();
              int num2 = stk1.top();
              stk1.pop();

              stk2.pop();

              cout << num2 << " " << k << " " << num1 << endl;

              if (k == '*') {
                stk1.push(num1 * num2);
              }
              if (k == '-') {
                stk1.push(num2 - num1);
              }
              if (k == '+') {
                stk1.push(num2 + num1);
              }

              if (stk2.empty()) {
                stk2.push(s[i]);
                break;
              }

              k = stk2.top();
              if ((k == '+' || k == '-') && (s[i] == '*' || s[i] == '(')) {
                stk2.push(s[i]);
                break;
              } else if (k == '(') {
                stk2.push(s[i]);
                break;
              }
            }
          }
        } else {
          stk2.push(s[i]);
        }

        ++i;
      } else {
        int num = getint(s, i);
        cout << "push " << num << endl;
        stk1.push(num);
      }
    }

    // while(!stk1.empty()){
    //     cout << stk1.top() << "\t";
    //     stk1.pop();
    // }

    // while(!stk2.empty()){
    //     cout << stk2.top() << "\t";
    //     stk2.pop();
    // }

    while (!stk2.empty()) {
      char k = stk2.top();
      stk2.pop();

      int num1 = stk1.top();
      stk1.pop();
      int num2 = stk1.top();
      stk1.pop();

      cout << num2 << " " << k << " " << num1 << endl;

      if (k == '*') {
        stk1.push(num1 * num2);
      }
      if (k == '-') {
        stk1.push(num2 - num1);
      }
      if (k == '+') {
        stk1.push(num2 + num1);
      }
    }

    // while(!stk1.empty()){
    //     cout << stk1.top() << "\t";
    //     stk1.pop();
    // }

    return stk1.top();
  }
};

int main() {
  string strs = "(3+4)*(5+(2-3))";

  Solution P;

  cout << P.solve(strs) << endl;

  return 0;
}