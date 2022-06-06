#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

    ListNode *reversalList(ListNode *head, int k)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *p3 = head;

        if(k != 1){
            p2 = p2->next;
            p3 = p3->next;
        }else{
            return head;
        }
        bool tag = true;
        int i = 0;
        while(i != k-1){
            if(tag){
                tag = false;
                p1->next = nullptr;
            }else{
                p1 = p2;
                p2 = p3;
            }
            if(i != k-2){
                p3 = p3->next;
            }
            p2->next = p1;
            i++;
        }
        return p3;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *P = head;
        int num = 0;
        bool tag = true;
        while(p1 != nullptr){
            ++num;
            p1 = p1->next;
            if(num == k){
                ListNode* H = reversalList(p2, k);
                p2->next = p1;
                num = 0;
                if(tag){
                    head = H;
                    P = p2;
                    tag = false;
                }else{
                    P->next = H;
                    P = p2;
                }
                p2 = p1;
            }
        }
        if(num < k){
            P->next = p2;
        }
        return head;
    }
};

class Solution1 {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};


int main()
{
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);

    Solution P;
    ListNode * H = P.reverseKGroup(p1, 2);

    while(H != nullptr){
        cout << H->val << "\t";
        H = H->next;
    }
    cout << endl;
}