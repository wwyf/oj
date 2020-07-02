/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
 */


/*
使用一个数组存放后缀数组和。一旦后缀数组变成了0，就可以删掉一部分。

经验教训：
1. 对于链表，常常使用一个dummy节点作为一个新的head，方便代码中各种边界情况的处理。

可优化的地方：

其他解法：
1. 前缀和！一个重要的想法是：两个相同的前缀和，意味着中间有一段子序列sum为0.
    1. 那么这个前缀和就可以使用hashmap存起来，如果发现索引为i和j的前缀和相同，那么意味着i+1 -> j 这一段可以被删掉。
    2. hashmap存放 index->pointer的映射，那么就可以很自然的删掉后面这一段
    3. https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solution/c-jian-ji-dai-si-lu-by-philhsu/
2. https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solution/java-hashmap-liang-ci-bian-li-ji-ke-by-shane-34/
    1. 同样是前缀和，这里注意到了，前缀和之间的嵌套，是对结果没什么影响的，通过这种方法，能够直接将最大的一层前缀和消掉。

*/


#include <iostream>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        bool isRemoved = true;
        while(isRemoved){
            head = removeZeroSum(head, isRemoved);
        }
        return head;
    }
    ListNode* removeZeroSum(ListNode* head, bool & isRemoved){
        int sums[1001];
        memset(sums, 0, 1001*sizeof(int));
        ListNode * ps[1001];
        ListNode * tempHead = new ListNode(0);
        tempHead->next = head;
        ps[0] = tempHead;
        sums[0] = 0;
        ListNode* cur = head;
        int curIndex = 1;
        while(cur!=NULL){
            ps[curIndex] = cur;
            for (int i = 1; i <= curIndex; i++){
                sums[i] = sums[i] + cur->val;
                if (sums[i] == 0){
                    // TODO
                    // i - curIndex sum to Zero
                    // delete i - curIndex nodes
                    // i-1, curIndex+1
                    ps[i-1]->next = ps[curIndex]->next;
                    isRemoved = true;
                    return tempHead->next;
                }
            }
            curIndex++;
            cur = cur->next;
        }
        isRemoved = false;
        return head;

    }
};
// @lc code=end

