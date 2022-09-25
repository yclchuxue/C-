/********************************
 * 链表中倒数第k个节点--剑指offer22
 * *****************************/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

class Solution 
{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode *p = head, *q = head;
        int index = 0;      //前后指针相差数
        while(p)
        {
            if(index == k)
            {
                break;
            }
            p = p->next;
            ++index;
        }
        while(p)
        {
            p = p->next;
            q = q->next;
        }
        return q;
    }

    ListNode* getKthFromEnd1(ListNode* head, int k){
        vector<ListNode*> lists;
        int len = 0;
        ListNode *p = head;
        while(p){
            len++;
            lists.push_back(p);
            p = p->next;
        }
        int index = len-k;
        return lists[index];
    }
};

int main()
{
    ListNode *head = nullptr, *tail = nullptr;
    int value, k;
    cin >> value;
    while(value != -1)
    {
        ListNode *p = new ListNode;
        p->val = value;
        p->next = nullptr;
        if(head == nullptr)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
        cin >> value;
    }
    cout << "请输入一个小于链表长度的数：";
    cin >> k;
    Solution P;
    ListNode *h = P.getKthFromEnd(head, k);
    while(h)
    {
        cout << h->val << "\t";
        h = h->next;
    }
    cout << endl;
    return 0;
}