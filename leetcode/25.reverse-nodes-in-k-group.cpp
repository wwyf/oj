/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (37.81%)
 * Likes:    1378
 * Dislikes: 278
 * Total Accepted:    204.7K
 * Total Submissions: 541.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
/*
√ Accepted
  √ 81/81 cases passed (20 ms)
  √ Your runtime beats 70.3 % of cpp submissions
  √ Your memory usage beats 77.42 % of cpp submissions (9.8 MB)
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (head == NULL){
           return NULL;
       }
       if (k == 1){
           return head;
       }
       int len = 0;
       ListNode * myhead = new ListNode(0);
       myhead->next = NULL;
       ListNode * tail = head;
       ListNode * newhead_tail = myhead;
       ListNode * temp = NULL;
       ListNode * cur = head;
       while(cur){
           len++;
           cur = cur->next;
       }
       cur = head;
       int nums = len/k;
       for (int j = 0; j < nums; j++){
            tail = cur;
            for (int i = 0; i < k; i++){
                temp = cur->next;
                cur->next = newhead_tail->next;
                newhead_tail->next = cur;
                cur = temp;
            }
            newhead_tail = tail;
       }
       newhead_tail->next = cur;
        temp = myhead->next;
       delete myhead;
       return temp;
    }
};

