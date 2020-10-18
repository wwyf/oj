/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return  head;
        if (head->next == nullptr) return head;
        
        // find mid using fast ans slow pointer
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *left_start = head;;
        ListNode *right_start = slow->next;
        ListNode *left_tail = slow;
        // partition the linked list into 2 part
        left_tail->next = nullptr;

        // sort
        left_start = sortList(left_start);
        right_start = sortList(right_start);

        // merge
        ListNode null_start;
        ListNode * cur = &null_start;
        while(left_start && right_start){
            if (left_start->val < right_start->val){
                cur->next = left_start;
                left_start = left_start->next;
            } else {
                cur->next = right_start;
                right_start = right_start->next;
            }
            cur = cur->next;
        }
        while(left_start){
            cur->next = left_start;
            left_start = left_start->next;
            cur = cur->next;
        }
        while(right_start){
            cur->next = right_start;
            right_start = right_start->next;
            cur = cur->next;
        }
        cur->next = nullptr;
        return null_start.next;
    }
};
// @lc code=end

