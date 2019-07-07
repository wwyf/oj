/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.11%)
 * Likes:    5453
 * Dislikes: 1397
 * Total Accepted:    921.2K
 * Total Submissions: 2.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
 
 #include <algorithm>
 using std::min;
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = 0, length2 = 0;
        ListNode * cp = nullptr;
        cp = l1;
        while (cp != nullptr ){
            cp = cp->next;
            length1++;
        }
        
        cp = l2;
        while (cp!= nullptr){
            cp = cp->next;
            length2++;
        }
        
        ListNode * head = new ListNode(0);
        cp = head;
        ListNode * cp1 = l1;
        ListNode * cp2 = l2;
        for (int i = 0; i < min(length1, length2); i++){
            int cur_sum = cp1->val + cp2->val + cp->val;
            int single_sum = cur_sum % 10;
            int carry_sum = cur_sum / 10;
            cp->val = single_sum;
            ListNode * next = new ListNode(carry_sum);
            cp->next = next;
            cp = cp->next;
            cp1 = cp1->next;
            cp2 = cp2->next;
        }
        
        while (cp1 != nullptr){
            int cur_sum = cp1->val + cp->val;
            int single_sum = cur_sum % 10;
            int carry_sum = cur_sum / 10;
            cp->val = single_sum;
            ListNode * next = new ListNode(carry_sum);
            cp->next = next;
            cp = cp->next;
            cp1 = cp1->next;
        }
        
        while (cp2 != nullptr){
            int cur_sum = cp2->val + cp->val;
            int single_sum = cur_sum % 10;
            int carry_sum = cur_sum / 10;
            cp->val = single_sum;
            ListNode * next = new ListNode(carry_sum);
            cp->next = next;
            cp = cp->next;
            cp2 = cp2->next;
        }
        
        

        if (cp->val == 0)
        {
            cp = head;
            while (cp->next->next != nullptr){
                cp = cp->next;
            }   
            ListNode * temp = cp->next;
            cp->next = nullptr;
            delete temp;
        }
        
        return head;
        
    }
};

