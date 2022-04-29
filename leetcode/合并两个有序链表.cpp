#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode *p1 = list1;
        struct ListNode *p2 = list2;

        struct ListNode * head = nullptr;
        struct ListNode * point = nullptr;

        if(p1 == nullptr){
            return p2;
        }
        if(p2 == nullptr){
            return p1;
        }

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                
                if(head == nullptr){
                    point = p1;
                    head = p1;
                }else{
                    point->next = p1;
                    point = point->next;
                }

                p1 = p1->next;
                point->next = nullptr;
            }else{
                
                if(head == nullptr){
                    point = p2;
                    head = p2;
                }else{
                    point->next = p2;
                    point = point->next;
                }

                p2 = p2->next;
                point->next = nullptr;
            }
        }

        if(p1 != nullptr && point != nullptr){
            point->next = p1;
        }
        if(p2 != nullptr && point != nullptr){
            point->next = p2;
        }

        return head;
    }
};


int main(){
    ListNode * head;
}