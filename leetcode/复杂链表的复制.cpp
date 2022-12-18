#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> cacheNode;
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(!cacheNode.count(head)){
            Node * ptr = new Node(head->val);
            // node.next = head->next;
            cacheNode[head] = ptr;
            ptr->next = copyRandomList(head->next);
            ptr->random = copyRandomList(head->random);
        }
        return cacheNode[head];
    }
};