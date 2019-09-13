/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.41%)
 * Likes:    2121
 * Dislikes: 160
 * Total Accepted:    447.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL){
            return NULL;
        }
        int len = 1;
        ListNode* cur = head;
        while (cur->next){
            cur = cur->next;
            len++;
        }
        int nth = len - n;
        if (nth == 0){
            return head->next;
        }
        else{
            ListNode* pre = head;
            ListNode* cur = head->next;
            while (nth > 1){
                pre = cur;
                cur = cur->next;
                nth--;
            }
            pre->next = cur->next;
        }
        return head;
    }
};

class Solution {
    public:
    ListNode * removeNthFromEnd(ListNode* head, int n){
        // only one pass
        // the key point is to use two pointers
        if (head == NULL){
            return NULL;
        }
        ListNode* look, *pre, *cur;
        int distance = 1;
        look = head->next;
        pre = NULL;
        cur = head;
        while (look){
            if (distance < n){
                distance += 1;
                look = look->next;
            }
            else{
                look = look->next;
                pre = cur;
                cur = cur->next;
            }
        }
        if (cur == head){
            return head->next;
        }
        else{
            pre->next = cur->next;
            return head;
        }

    }
};

