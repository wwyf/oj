/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
    ListNode *detectCycle(ListNode *head) {
        ListNode * cur = head;
        unordered_set<ListNode*> visit;
        while(cur){
            if (visit.find(cur) != visit.end()){
                return cur;
            }
            visit.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};
// @lc code=end

