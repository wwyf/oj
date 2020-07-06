/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include <map>
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode * lp = head, * fp = head;
        while (fp->next != NULL){
            // step 1
            lp = lp->next;
            fp = fp->next;
            if (fp->next != NULL){
                fp = fp->next;
                if (fp == lp){
                    return true;
                }
            } else{
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

