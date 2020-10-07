/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <iostream>
#include <algorithm>
using namespace std;
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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeR(root);
        return ans;
    }
    void diameterOfBinaryTreeR(TreeNode* root) {
        if (root == nullptr){
            return ;
        }
        ans = std::max(ans, getDepth(root->left)+getDepth(root->right));
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
    }
    int getDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        return std::max(getDepth(root->left), getDepth(root->right))+1;
    }
};
// @lc code=end

