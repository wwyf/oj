/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

/*

1. 我的递归
2. 一种更好的递归思路：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/c-jing-dian-di-gui-si-lu-fei-chang-hao-li-jie-shi-/
3. 标答：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        TreeNode * commonRoot;
        if (root->left != NULL){
            commonRoot = lowestCommonAncestor(root->left, p, q);
            if (commonRoot != NULL){
                return commonRoot;
            }
        }
        if (root->right != NULL){
            commonRoot = lowestCommonAncestor(root->right, p,q);
            if (commonRoot != NULL){
                return commonRoot;
            }
        }
        if (commonRoot == NULL){
            if (findNode(root,q) && findNode(root,p)){
                return root;
            } else {
                return NULL;
            }
        }
        return NULL;
    }
    bool findNode(TreeNode* root, TreeNode* n){
        if (root == NULL) return false;
        if (root == n) return true;
        return findNode(root->left, n)||findNode(root->right, n);
    }
};
// @lc code=end

