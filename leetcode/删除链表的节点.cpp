#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *ptr = head, *ret = head;
        if(head && head->val == val) return head->next;
        head = head->next;
        while(head) { 
            if(head->val == val) {
                ptr->next = head->next;
                break;
            }else{
                ptr = head;
                head = head->next;
            }
        }

        return ret;
    }
};