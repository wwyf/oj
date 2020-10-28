/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <iostream>
#include <string>
#include <algorithm>
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
    int ans;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        ans = root->val;
        maxGain(root);
        return ans;
    }
    int maxGain(TreeNode* root){
        if (root==nullptr){
            return 0;
        }
        int left_gain = max(maxGain(root->left), 0);
        int right_gain = max(maxGain(root->right), 0);
        int cur_ans = root->val + left_gain + right_gain;
        ans = max(ans, cur_ans);
        // key！！！！
        return root->val + max(left_gain, right_gain);
    }
};
// @lc code=end

