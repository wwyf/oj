/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
/*
1. 遍历一次，查看顺序？不够
2. 递归：两个子树相同，根节点也相同，然后就相同。可以，搞定。

阅读：https://leetcode-cn.com/problems/same-tree/solution/xie-shu-suan-fa-de-tao-lu-kuang-jia-by-wei-lai-bu-/

*/


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL){
            return true;
        }
        if (p != NULL && q != NULL){
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
                if (p->val == q->val){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

