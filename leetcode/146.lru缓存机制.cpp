/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// @lc code=start
struct Node{
    Node * prev;
    Node * next;
    int key;
    int value;
    Node(){
        prev = NULL;
        next = NULL;
        key = 0;
        value = 0;
    }
};

class LRUCache {
public:
    Node * head;
    Node * tail;
    int capacity;
    int size;
    unordered_map<int, Node *> k2n;
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->size = 0;
    }
    void access(Node * n){
        // bug!!!
        if (n == head->next){
            return;
        }
        // put n to head
        Node * tmpNext = n->next;
        Node * tmpPrev = n->prev;
        // next
        n->next = head->next;
        head->next = n;
        tmpPrev->next = tmpNext;
        // prev
        n->prev = head;
        n->next->prev = n;
        tmpNext->prev = tmpPrev;
    }
    int get(int key) {
        auto findNodeIter = k2n.find(key);
        if (findNodeIter == k2n.end()){
            // can not find key in k2n
            return -1;
        } else {
            this->access(findNodeIter->second);
            return findNodeIter->second->value;
        }
    }
    void put(int key, int value) {
        auto findNodeIter = k2n.find(key);
        if (findNodeIter == k2n.end()){
            // can not find key in k2n
            // must put new node
            if (this->size < this->capacity){
                // directly put new node to head
                Node * newNode = new Node();
                newNode->key = key;
                newNode->value = value;
                newNode->next = head->next;
                newNode->prev = head;
                head->next = newNode;
                newNode->next->prev = newNode;
                this->size++;
                k2n[key] = newNode;
            } else {
                // move tail to head and modify
                Node * tailNode = tail->prev;
                // delete from map k2n
                k2n.erase(tailNode->key);
                this->access(tailNode);
                tailNode->key = key;
                tailNode->value = value;
                k2n[key] = tailNode;
            }
        } else {
            this->access(findNodeIter->second);
            findNodeIter->second->value = value;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

