/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr){
            return head;
        }
        int len = 0;
        ListNode * cur = head;
        ListNode * tail = 0;
        while(cur){
            tail = cur;
            cur = cur->next;
            len++;
        }
        ListNode* sep_point = head;
        int move_distence = k % len;
        if(move_distence == 0){
            return head;
        }
        for (int i = 0; i < (len-move_distence-1); i++){
            sep_point = sep_point->next;
        }
        // head.. sep_point | sep_point->next .. tail ->head
        tail->next = head;
        head = sep_point->next;
        sep_point->next = NULL;
        return head;
    }
};
// @lc code=end

