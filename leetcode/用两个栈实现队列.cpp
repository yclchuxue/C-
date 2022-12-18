#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> instack, outstack;

    void in2out(){
        while(!instack.empty()){
            int num = instack.top();
            instack.pop();
            outstack.push(num);
        }
    }
public:

    CQueue() {
        
    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        if(outstack.empty()){
            if(instack.empty()){
                return -1;
            }
            in2out();
        }
        int ret = outstack.top();
        outstack.pop();
        return ret;
    }
};
