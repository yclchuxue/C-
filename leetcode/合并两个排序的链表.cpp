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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret, *ptr, *ptr1 = l1, *ptr2 = l2;

        if(!ptr1) return ptr2;
        if(!ptr2) return ptr1;

        bool head = false;
        while (ptr1 && ptr2) {
            if(ptr1->val < ptr2->val){
                if(!head) {
                    ret = ptr1;
                    ptr = ptr1;
                    head = true;
                }else{
                    ptr->next = ptr1;
                }
                ptr = ptr1;
                ptr1 = ptr1->next;
                ptr->next = nullptr;
            }else{
                if(!head) {
                    ret = ptr2;
                    ptr = ptr2;
                    head = true;
                }else{
                    ptr->next = ptr2;
                }
                ptr = ptr2;
                ptr2 = ptr2->next;
                ptr->next = nullptr;
            }
        }

        if(ptr1){
            ptr->next = ptr1;
        }
        if(ptr2){
            ptr->next = ptr2;
        }

        return ret;
    }
};