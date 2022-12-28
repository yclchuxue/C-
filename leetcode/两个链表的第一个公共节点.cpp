#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> occ;
        ListNode* ptr = headA;
        while(ptr){
            occ.insert(ptr);
            ptr = ptr->next;
        }

        ptr = headB;
        while (ptr) {
            if(occ.count(ptr)){
                return ptr;
            }else{
                ptr = ptr->next;
            }
        }   
        return nullptr;
    }
};