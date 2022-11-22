#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

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
    struct node {
        int val;
        ListNode *ptr;

        //默认是大顶堆，即top为最大； 所以需要重载 <
        //需要的是小顶堆，需要的是 >
        //当使用默认定义优先队列时:// priority_queue<node> p;
        //却想是小顶堆,则需要反着定义 <
        bool operator < (const node &rhs) const {
            return val > rhs.val;
        }


        //priority_queue<node, vector<node>, greater<node>> p;
        bool operator > (const node &rhs) const {
            return val > rhs.val;
        }
    };

    // priority_queue<node> p;

    priority_queue<node, vector<node>, greater<node>> p;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // for(auto it = lists.begin(); it != lists.end(); it++){
        //     p.push({&it->val, it->next});
        // }
        for (auto node: lists) {
            if (node) p.push({node->val, node});
        }

        ListNode head, *tail = &head;
        while(!p.empty()){
            auto x = p.top();
            p.pop();

            tail->next = x.ptr;
            tail = x.ptr;
            if(x.ptr && x.ptr->next != nullptr) {
                p.push({x.ptr->next->val, x.ptr->next});
            }
        }

        return head.next;
    }
};