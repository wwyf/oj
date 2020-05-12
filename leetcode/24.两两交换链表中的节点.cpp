/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode root(0);
        root.next = head;

        ListNode * p = &root;
        ListNode * s = NULL, * ss = NULL, * n = NULL;
        while (p != NULL){
            s = p->next;
            if (s == NULL){
                break;
            }
            ss = s->next;
            if (ss == NULL){
                break;
            }
            n = ss->next;
            // 开始交换
            p->next = ss;
            s->next = n;
            ss->next = s;
            // 交换完成，然后切换到下面两个节点
            p = s;
        }
        return root.next;
    }
};
// @lc code=end

