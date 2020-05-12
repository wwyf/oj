/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */


/*
很简单了。
主要是考察进制之间的转换，这里的话则就是在从高位向低位遍历的过程里如何转换进制需要想一想。
*/

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
    int getDecimalValue(ListNode* head) {
        if(head == NULL){
            return 0;
        }
        int r = 0;
        ListNode* cur = head;
        while(cur){
            r = r*2 + cur->val*1;
            cur = cur->next;
        }
        return r;
    }
};
// @lc code=end

