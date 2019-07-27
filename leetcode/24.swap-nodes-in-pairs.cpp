/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (45.47%)
 * Likes:    1265
 * Dislikes: 110
 * Total Accepted:    335.6K
 * Total Submissions: 736.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*
对指针，内存的操作需要尤为关注。
很容易乱
最好在变量命名的时候，以实体为思考方向去明明，去思考代码。
 */
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* newHead = NULL;
        ListNode* previous = NULL;
        while (cur != NULL && cur->next != NULL){
            ListNode* left = cur;
            ListNode* right = cur->next;
            ListNode* remains = cur->next->next;
            left->next = remains;
            right->next = left;
            if (cur != head){
                previous->next = right;
            }
            else{
                newHead = right;
            }
            previous = left;
            cur = left->next;
        }
        return newHead;
    }
};

