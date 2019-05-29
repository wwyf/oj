/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.23%)
 * Likes:    2225
 * Dislikes: 312
 * Total Accepted:    583.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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

#include <iostream>
using namespace std;
// #define DEBUG

#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif
/*
    反思：很简单的题目，在编码的时候，思维还是有点慢
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * ans=NULL;
        // can solve (l1 and l2 is NULL) (l1 is NULL and l2 X)
        if (l1 == NULL){
            return l2;
        }
        else if (l2 == NULL){
            // l1 not NULL and l2 is NULL
            return l1;
        }
        else{
            // l1 and l2 is not NULL
            // set head
            if (l1->val <= l2->val){
                ans = l1;
                l1 = l1->next;
            }
            else{
                ans = l2;
                l2 = l2->next;
            }
            ListNode * cur = ans;
            while ( l1 != NULL && l2 != NULL){
                if (l1->val <= l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }
                else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            // l1 or l2 is NULL
            while(l1 != NULL){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            while(l2 != NULL){
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }

        return ans;
        
    }
};

