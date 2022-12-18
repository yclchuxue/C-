#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>

using namespace std;

class MinStack {
private:
    stack<int> stacks;
    stack<int> min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        stacks.push(x);
        min_stack.push(::min(min_stack.top(), x));
    }
    
    void pop() {
        min_stack.pop();
        stacks.pop();
    }
    
    int top() {
        return stacks.top();
    }
    
    int min() {
        return min_stack.top();
    }
};