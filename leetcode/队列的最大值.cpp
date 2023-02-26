#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class MaxQueue {
private:
    queue<int> que;

    map<int, int> nums;

public:
    MaxQueue() {
    }
    
    int max_value() {
        if(!nums.empty()){
            auto it = nums.rbegin();
            return it->first;
        }
        return -1;
    }
    
    void push_back(int value) {
        que.push(value);
        nums.emplace(value, value);
    }
    
    int pop_front() {
        int ret = -1;
        if(!que.empty()){
            ret = que.front();
            que.pop();
            auto it = nums.find(ret);
            if(it != nums.end())    nums.erase(it);
        }
        return ret;
    }
};

int main(){
    map<int, int> nums;

    nums.emplace(1,1);
    nums.emplace(2,2);
    nums.emplace(3,3);
    nums.emplace(4,4);

    for(auto it = nums.begin(); it != nums.end();it++){
        cout << it->first << "\t";
    }
    cout << endl;

    auto it = nums.find(2);
    nums.erase(it);

    for(auto it = nums.begin(); it != nums.end();it++){
        cout << it->first << "\t";
    }
    cout << endl;

    cout << (nums.rbegin())->first << endl;
}