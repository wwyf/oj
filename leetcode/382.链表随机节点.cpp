/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */
#include <iostream>
#include <random>
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
    int len;
    ListNode * head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) {
        this->len = 0;
        ListNode * cur = head;
        while (cur != NULL){
            this->len ++;
            cur = cur->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = rand() % this->len;
        ListNode * cur = head;
        int count = 0;
        while(cur!=NULL && count < index){
            cur = cur->next;
            count ++;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

