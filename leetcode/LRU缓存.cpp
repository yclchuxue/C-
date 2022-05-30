#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        count = capacity;
    }
    
    int get(int key) {  
        auto it = table.find(key);
        if(it != table.end()){
            li.splice(li.begin(), li, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = table.find(key);
        if(it != table.end()){
            li.splice(li.begin(), li, it->second);
            it->second->second = value;
            return ;
        }

        // 在list头部生成一个元素
        li.emplace_front(key, value);
        table[key] = li.begin();

        if(table.size() > count){
            table.erase(li.back().first);
            li.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int,int>>::iterator> table;
    list<pair<int, int>> li;
    int count;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {

    }
    
    int get(int key) {
        auto it = _table.find(key);
        if (it != _table.end()) {
            _lru.splice(_lru.begin(), _lru, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = _table.find(key);
        if (it != _table.end()) {
            _lru.splice(_lru.begin(), _lru, it->second);
            it->second->second = value;
            return;
        }
        
        _lru.emplace_front(key, value);
        _table[key] = _lru.begin();
        
        if (_table.size() > _capacity) {
            _table.erase(_lru.back().first);
            _lru.pop_back();
        }
    }
private:
    unordered_map<int, std::list<std::pair<int, int>>::iterator> _table;
    std::list<std::pair<int, int>> _lru;
    int _capacity;
};