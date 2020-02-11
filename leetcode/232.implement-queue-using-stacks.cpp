/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// 1. 一种实现：有时pop是O(1)，有时push是O(1)
// 2. 另一种实现：push的时候将数字push到stack底部，这样子pop一定是O(1)，而push是O(n)
// 3. 另一种实现：正常push，pop的时候将整个stack翻转过来然后再pop，这样：pop  O(n)  push O(1)

#include <stack>

class MyQueue {
public:
    std::stack<int> mystack;
    std::stack<int> temp;
    int reversed = 0;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        restore();
        mystack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        reverse();
        int num = temp.top();
        temp.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        reverse();
        int num = temp.top();
        return num;
    }
    void reverse(){
        if (reversed == 0){
            while(mystack.size() != 0) {
                temp.push(mystack.top());
                mystack.pop();
            }
            reversed = 1;
        }
    }
    void restore(){
        if (reversed == 1){
            while(temp.size() != 0){
                mystack.push(temp.top());
                temp.pop();
            }
            reversed = 0;
        }
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        if (reversed == 0){
            return mystack.size() == 0;
        }
        else {
            return temp.size() == 0;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

