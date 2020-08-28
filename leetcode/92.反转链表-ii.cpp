/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include <iostream>
using namespace std;
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n){
            return head;
        }
        ListNode top(0);
        top.next = head;
        ListNode* topp = &top;

        int count = 0;
        ListNode* head_p = NULL;
        ListNode* tail_n = NULL;
        ListNode* cur = topp;
        ListNode* temp_head = NULL;
        ListNode* temp_tail = NULL;
        while(cur != NULL){
            // cout << count << endl;
            // cout << flush << endl;
            // cur is count th
            if (count == m-1){
                head_p = cur;
                temp_head = cur->next; 
                temp_tail = cur->next;
            } else if (m <= count && count < n){
                ListNode* temp = cur;
                cur = cur->next; 
                temp->next = temp_head;
                temp_head = temp;
                count++;
                continue;
            } else if (count == n){
                temp_tail->next = cur->next;
                cur->next = temp_head;
                temp_head = cur;
                head_p->next = temp_head;
                break;
            }
            cur = cur->next;
            count++;
            // cout << count << endl;
        }
        return topp->next;
        
    }
};
// @lc code=end

