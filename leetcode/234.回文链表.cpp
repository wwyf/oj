/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

/* 三种方法
https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
感觉自己思路还是太局限了。

如果要O(1)空间的话，需要手动反转链表可还行

https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-1zhan-2kuai-man-zhi-zhen-fan-zhu/
https://leetcode-cn.com/problems/palindrome-linked-list/solution/wo-de-kuai-man-zhi-zhen-du-cong-tou-kai-shi-gan-ju/


栈
```
Accepted
26/26 cases passed (60 ms)
Your runtime beats 5.57 % of cpp submissions
Your memory usage beats 5.72 % of cpp submissions (14.7 MB)
```
 */
#include <stack>
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        stack<int> s;
        ListNode * cur = head;
        while (cur != NULL){
            s.push(cur->val);
            cur = cur->next;
        }
        cur = head;
        int val;
        while (cur != NULL){
            val = s.top();
            s.pop();
            if (val != cur->val){
                return false;
            }
            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end

