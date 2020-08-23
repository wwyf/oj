/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
/*
Accepted

165/165 cases passed (8 ms)

Your runtime beats 99.65 % of cpp submissions

Your memory usage beats 7.43 % of cpp submissions (7.8 MB)
*/
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        } else if (head->next == NULL){
            return head;
        }
        ListNode * new_next = deleteDuplicates(head->next);
        if (head->val == new_next->val){
            head->next = new_next->next;
        } else {
            head->next = new_next;
        }
        return head;
    }
};
// @lc code=end

