/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (34.43%)
 * Likes:    2646
 * Dislikes: 172
 * Total Accepted:    414.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
#include <vector>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
/*
√ Accepted
  √ 131/131 cases passed (396 ms)
  √ Your runtime beats 9.31 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (10.6 MB)
*/
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        ListNode * cur = NULL;
        int len = lists.size();
        int min_index = 0;
        bool end=false;
        while(!end){
            end = true;
            int minium = INT_MAX;
            for (int i = 0; i < len; i++){
                if (lists[i] != NULL && minium > lists[i]->val){
                    end = false;
                    minium = lists[i]->val;
                    min_index = i;
                }
            }
            if (end) break;
            if (head == NULL){
                head = lists[min_index];
                cur = head;
            }
            else{
                cur->next = lists[min_index];
                cur = cur->next;
            }
            lists[min_index] = lists[min_index]->next;
        }
        return head;
    }
};

/*
√ Accepted
  √ 131/131 cases passed (20 ms)
  √ Your runtime beats 98.82 % of cpp submissions
  √ Your memory usage beats 96.43 % of cpp submissions (10.7 MB)
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0){
            return NULL;
        }
        int inteval = 1;
        while(inteval <= len){
            int i = 0;
            while (i+inteval < len){
                lists[i] = mergeTwoLists(lists[i], lists[i+inteval]);
                i += 2*inteval;
            }
            // if (i < len){
            //     lists[i-2*inteval] = mergeTwoLists(lists[i-2*inteval], lists[i]);
            // }
            inteval *= 2;
        }
        return lists[0];
    }
    ListNode * mergeTwoLists(ListNode* left, ListNode* right){
        ListNode* head = NULL;
        if (left == NULL){
            return right;
        }
        if (right == NULL){
            return left;
        }
        if (left->val < right->val){
            head = left;
            left = left->next;
        }
        else{
            head = right;
            right = right->next;
        }
        ListNode* cur = head;
        while (left != NULL && right != NULL){
            if (left->val < right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left == NULL){
            cur->next = right;
        }
        else if (right == NULL){
            cur->next = left;
        }
        return head;
    }
};
