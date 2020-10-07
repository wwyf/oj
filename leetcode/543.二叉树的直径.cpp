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
        getDepth(root);
        return ans;
    }
    int getDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        ans = std::max(ans, left+right);
        return std::max(left, right)+1;
    }
};
// @lc code=end

