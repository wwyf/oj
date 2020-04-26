/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL){
            return 0;
        }
        int leftSum = 0;
        if (root->val > L){
            leftSum = rangeSumBST(root->left, L, R);
        }
        int middleSum = 0;
        if (L <= root->val && root->val <= R){
            middleSum = root->val;
        }
        int rightSum = 0;
        if (root->val < R){
            rightSum = rangeSumBST(root->right, L, R);
        }
        return leftSum+middleSum+rightSum;
    }
};
// @lc code=end

