#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    stack<int> stacks;
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> rets;
        while(head){
            stacks.push(head->val);
            head = head->next;
        }
        while(!stacks.empty()){
            rets.push_back(stacks.top());
            stacks.pop();
        }

        return rets;
    }
};