/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

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
    // 减少无谓的判断，似乎没什么效果
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL){
            return 0;
        }
        if (L <= root->val && root->val <= R){
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
        else if (root->val > R){
            return rangeSumBST(root->left, L, R);
        }
        else if (root->val < L){
            return rangeSumBST(root->right, L, R);
        }
        else {
            return 0;
        }
    }
};

// class Solution {
// public:
//     int rangeSumBST(TreeNode* root, int L, int R) {
//         if (root == NULL){
//             return 0;
//         }
//         int leftSum = 0;
//         if (root->val > L){
//             leftSum = rangeSumBST(root->left, L, R);
//         }
//         int middleSum = 0;
//         if (L <= root->val && root->val <= R){
//             middleSum = root->val;
//         }
//         int rightSum = 0;
//         if (root->val < R){
//             rightSum = rangeSumBST(root->right, L, R);
//         }
//         return leftSum+middleSum+rightSum;
//     }
// };
// @lc code=end

