/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenRoot(root);
    }
    TreeNode*  flattenRoot(TreeNode* root){
        if (root == NULL) return root;
        if (root->left&&root->right){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode * new_left_tail = flattenRoot(left);
            TreeNode * new_right_tail = flattenRoot(right);
            new_left_tail->right = right;
            new_left_tail->left = NULL;
            root->right = root->left;
            root->left = NULL;
            return new_right_tail;
        } else if (root->left){
            TreeNode* left = root->left;
            TreeNode * new_left_tail = flattenRoot(left);
            root->right = root->left;
            root->left = NULL;
            return new_left_tail;
        } else if (root->right){
            TreeNode* right = root->right;
            TreeNode * new_right_tail = flattenRoot(right);
            return new_right_tail;
        } 
        return root;
    }
};
// @lc code=end

