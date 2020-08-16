/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 */
#include <iostream>
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
/*
Accepted

36/36 cases passed (68 ms)

Your runtime beats 86.87 % of cpp submissions

Your memory usage beats 35.19 % of cpp submissions (35 MB)
*/
    TreeNode* searchBST_r(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;
        if (root->val < val ){
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
/*
Accepted

36/36 cases passed (72 ms)

Your runtime beats 72.74 % of cpp submissions

Your memory usage beats 35.19 % of cpp submissions (35 MB)
*/
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * cur = root;
        while (cur != NULL && cur->val != val){
            if (cur->val < val){
                cur = cur->right;
            }else {
                cur = cur->left;
            }
        }
        return cur;
    }
};
// @lc code=end


