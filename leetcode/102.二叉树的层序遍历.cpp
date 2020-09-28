/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return vector<vector<int>>{};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level_count = 0;
        while(!q.empty()){
            int cur_count = q.size();
            vector<int> level;
            for (int i = 0; i < cur_count; i++){
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            ans.emplace_back(level);
            // ans.push_back(level);
        }
        return ans;
    }
};
// @lc code=end

