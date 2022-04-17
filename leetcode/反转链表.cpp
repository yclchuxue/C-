#include <iostream>
#include <cstring>

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *q = nullptr;
        ListNode *p = head;

        if(head == nullptr) return head;

        while(p->next != nullptr)
        {
            if(head->next != nullptr)
            {
                head = head->next;
            }
            p->next = q;

            q = p;
            p = head;
        }

        p->next = q;

        return head;
    }
};

// int main()
// {

// }