/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <iostream>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#include <queue>
using namespace std;
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            TreeNode * t = q.front();
            q.pop();
            ans++;
            if (t->left != NULL) q.push(t->left);
            if (t->right != NULL) q.push(t->right);
        }
        return ans;
    }
};
// @lc code=end

