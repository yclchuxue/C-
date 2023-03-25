#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

struct ListNode{
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode() :prev(nullptr), next(nullptr) {}
    ListNode(int val_) : val(val_), next(nullptr), prev(nullptr) {}
    ListNode(int val_, ListNode*pre, ListNode*nex) : val(val_), prev(pre), next(nex) {}
};

class LRUCache1 {
private:
    int size_;
    map<int, ListNode*> maps;
    ListNode* head;
    ListNode* tail;
public:
    LRUCache1(int capacity) : size_(capacity){
        head = new ListNode();
        tail = new ListNode();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(maps.find(key) != maps.end()){

        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        // if(maps)
    }
};

struct Node{
    int key;
    int value;
    Node() :key(0), value(0) {}
    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
private:
    int size_;
    map<int, list<Node>::iterator> maps;
    list<Node> lists;
public:
    LRUCache(int capacity) : size_(capacity){
        
    }
    
    int get(int key) {
        if(maps.find(key) != maps.end()){
            if
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
    }
};