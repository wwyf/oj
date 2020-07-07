/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

#include <vector>
using namespace std;
// @lc code=start
struct Item{
    int key;
    int value;
    int oldIndex;
};

class LRUCache {
public:
    vector<Item> cache;
    int c;
    int size;
    LRUCache(int capacity) {
        cache = vector<Item>(capacity);
        this->c = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        int findIndex = this->find(key);
        if (findIndex == -1){
            return -1;
        } else{
            return cache[findIndex].value;
        }
    }
    
    int find(int key){
        int findIndex = -1;
        for (int i = 0; i < this->size; i++){
            if (cache[i].key == key){
                findIndex = i;
            }
            cache[i].oldIndex++;
        }
        if (findIndex != -1){
            cache[findIndex].oldIndex = 0;
        }
        return findIndex;
    }
    int findOldest(){
        int oldIndex = 0;
        int oldI = 0;
        for (int i = 0; i < this->size; i++){
            if (cache[i].oldIndex > oldIndex){
                oldIndex = cache[i].oldIndex;
                oldI = i;
            }
        }
        return oldI;
    }
    void put(int key, int value) {
        int findIndex = this->find(key);
        if (findIndex != -1){
            cache[findIndex].value = value;
        } else {
            // not found
            if (this->size < this->c){
                cache[this->size].key = key;
                cache[this->size].value = value;
                cache[this->size].oldIndex = 0;
                this->size++;
            } else {
                // find oldest element
                int oldI = findOldest();
                cache[oldI].key = key;
                cache[oldI].value = value;
                cache[oldI].oldIndex = 0;
            }
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

