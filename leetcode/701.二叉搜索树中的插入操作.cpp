/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */
#include <iostream>
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
/*
Accepted

35/35 cases passed (108 ms)

Your runtime beats 68.19 % of cpp submissions

Your memory usage beats 19.69 % of cpp submissions (38.5 MB)
*/
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==NULL){
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        while(cur != NULL){
            if (cur->val < val){
                if (cur->right){
                    cur = cur->right;
                } else {
                    break;
                }
            } else {
                if (cur->left){
                    cur = cur->left;
                } else {
                    break;
                }
            }
        }
        if (cur->val < val){
            cur->right = new TreeNode(val);
        } else {
            cur->left = new TreeNode(val);
        }
        return root;
        
    }
};
// @lc code=end

