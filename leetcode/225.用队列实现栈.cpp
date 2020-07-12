/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

/*
Accepted
16/16 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6.9 MB)

这里提到了三种模拟的思路
https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-dui-lie-shi-xian-zhan-by-leetcode/

*/

#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q, qt;
    MyStack() {
        return;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = q.size();
        for (int i = 0; i < len-1; i++){
            qt.push(q.front());
            q.pop();
        }
        int ans = q.front();
        //q = qt;
        q.swap(qt); // 使用swap之后，速度极快
        qt = queue<int>{};
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int len = q.size();
        for (int i = 0; i < len-1; i++){
            qt.push(q.front());
            q.pop();
        }
        int ans = q.front();
        qt.push(q.front());
        //q = qt;
        q.swap(qt); // 使用swap之后，速度极快
        qt = queue<int>{};
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

