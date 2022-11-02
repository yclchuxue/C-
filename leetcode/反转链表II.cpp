#include <iostream>
#include <vector>
#include <cstring>

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

    void print(ListNode*head){
        while(head != nullptr){
            cout << head->val << "\t";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right){
            return head;
        }

        ListNode *ll_ptr = nullptr, *l_ptr = nullptr, *n_ptr = nullptr;
        ListNode *r_ptr = nullptr, *rr_ptr = nullptr, *ret = head;
        int index = 1, tag = 0;
        while(1){
            if(head != nullptr){
                if(tag == 0){
                    if(left == 1){
                        ListNode *ptr = head;
                        head = head->next;
                        ll_ptr = nullptr;
                        l_ptr = ptr;
                        n_ptr = l_ptr;
                        l_ptr->next = nullptr;
                        index++;
                        tag = 2;
                    }else if(index+1 == left){
                        ListNode *ptr = head;
                        head = head->next;
                        ll_ptr = ptr;
                        l_ptr = head;
                        n_ptr = l_ptr;
                        l_ptr->next = nullptr;
                        index++;
                        tag = 1;
                    }else{
                        head = head->next;
                        index++;
                    }
                }else{

                    // if(n_ptr == nullptr){
                    //     n_ptr = l_ptr;
                        
                    //     n_ptr = head;
                    //     n_ptr->next = l_ptr;
                    // }else{
                    ListNode *ptr = head;
                    head = head->next;
                    ptr->next = n_ptr;
                    r_ptr = ptr;
                    n_ptr = ptr;
                    // }

                    if(index == right){

                        if(head != nullptr){
                            rr_ptr = head;
                        }else{
                            rr_ptr = nullptr;
                        }

                        // ListNode *ptr = head;
                        // head = head->next;
                        // ptr->next = n_ptr;
                        // n_ptr = ptr;

                        l_ptr->next = rr_ptr;

                        if(ll_ptr != nullptr){
                            ll_ptr->next = r_ptr;
                        }else{
                            ret = r_ptr;
                            cout << r_ptr->val << endl;
                            cout << r_ptr->next->val << endl;
                            cout << l_ptr->val << endl;
                        }
                        // if(right-left == 1){
                        //     r_ptr->next = l_ptr;
                        // }
                        break;
                    }

                    
                    index++;
                }
            }else{
                break;
            }
        }
        return ret;
    }
};

int main(){

    ListNode node(5), *p = nullptr;
    ListNode t4(4, &node);
    ListNode t3(3, &t4);
    ListNode t2(2, &t3);
    ListNode t1(1, &t2);

    Solution P;
    P.print(&t1);
    ListNode *ret = P.reverseBetween(&t1, 2, 4);
    // P.print(ret);
}