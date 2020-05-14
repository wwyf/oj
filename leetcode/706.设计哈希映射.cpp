/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

/*
这也太简单了吧？？
为什么这样的实现还能慢
但是这个，内存用量确实大：

Accepted
33/33 cases passed (240 ms)
Your runtime beats 52.33 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (185.2 MB)

可能慢在申请内存上了。

*/

#include <iostream>
// @lc code=start
const int base = 5023;
struct Node {
    int key;
    int val;
    Node * next;
    Node(): key(-1), val(-1), next(NULL) {}
    Node(int key, int val): key(key), val(val), next(NULL) {}
};

class MyHashMap {
    int capacity = base+10;
    Node* data[base+10];
public:
    int hash(int key){
        return key % base;
    }
    /** Initialize your data structure here. */
    MyHashMap() {
        // 建立一个初始节点
        for (int i = 0; i < this->capacity; i++){
            data[i] = new Node();
        }
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        Node* cur = data[index];
        while(cur->next){
            if(cur->next->key == key){
                cur->next->val = value;
                break;
            }
            cur = cur->next;
        }
        if (!cur->next){
            Node * newNode = new Node(key, value);
            cur->next = newNode;
        }
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        Node* cur = data[index];
        while (cur->next){
            if(cur->next->key == key){
                return cur->next->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        Node * cur = data[index];
        while (cur->next){
            if (cur->next->key == key){
                // 删除那个节点
                Node * deleteNode = cur->next;
                cur->next = deleteNode->next;
                delete deleteNode;
                break;
            }
            cur = cur->next;
        }
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

