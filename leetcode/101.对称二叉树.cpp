/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){return true;}
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode * left, TreeNode * right){
        if (left == nullptr && right == nullptr){
            return true;
        }
        if (left == nullptr || right == nullptr){
            return false;
        }
        auto r1 = isSymmetric(left->right, right->left);
        auto r2 = isSymmetric(left->left, right->right);
        auto r3 = left->val == right->val;
        return r1 && r2 && r3;
    }
};
// @lc code=end

