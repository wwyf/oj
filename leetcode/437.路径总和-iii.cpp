/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include <iostream>
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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL){
            return 0;
        }
        int ans = 0;
        ans += pathSum(root->left, sum);
        ans += pathSum2(root, sum);
        ans += pathSum(root->right, sum);
        return ans;
    }
    int pathSum2(TreeNode* root, int sum){
        if (root == NULL){
            return 0;
        }
        int ans = 0;
        if (root->val == sum){
            ans += 1;
        }
        ans += pathSum2(root->left, sum-root->val);
        ans += pathSum2(root->right, sum-root->val);
        return ans;

    }
};
// @lc code=end

