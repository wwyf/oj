/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class MinStack {
    stack<pair<int, int>> mystack;
public:
    /** initialize your data structure here. */
    MinStack() {
        ;
    }
    
    void push(int x) {
        if (mystack.empty()){
            mystack.push(pair(x,x));
        } else {
            auto top_node = mystack.top();
            if (x < top_node.second){
                mystack.push(pair(x,x));
            } else {
                mystack.push(pair(x,top_node.second));
            }
        }
    }
    
    void pop() {
        mystack.pop();
    }
    
    int top() {
        return mystack.top().first;
    }
    
    int getMin() {
        return mystack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

