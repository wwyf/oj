/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA = headA;
        ListNode * curB = headB;
        while(curA != nullptr && curB != nullptr){
            if (curA == curB){
                return curA;
            }
            if (curA->next == nullptr && curB->next == nullptr){
                return nullptr;
            }

            if (curA->next){
                curA = curA->next;
            } else {
                curA = headB;
            }
            if (curB->next){
                curB = curB->next;
            } else {
                curB = headA;
            }
        }    
        return nullptr;
    }
};
// @lc code=end

