/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include <unordered_map>
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
struct NodeMoney{
    int steal_root;
    int not_steal_root;
};
class Solution {
public:
    int rob(TreeNode* root) {
        auto ans = robRoot(root);
        return max(ans.steal_root, ans.not_steal_root);
    }
    NodeMoney robRoot(TreeNode*root){
        if (root == NULL){
            return NodeMoney({0,0});
        }
        if (root->right == NULL && root->left == NULL){
            return NodeMoney({root->val, 0});
        }
        // normal
        NodeMoney ans;
        
        auto leftMoney = robRoot(root->left);
        auto rightMoney = robRoot(root->right);
        ans.steal_root = root->val + leftMoney.not_steal_root + rightMoney.not_steal_root;
        ans.not_steal_root = max(leftMoney.steal_root, leftMoney.not_steal_root)  + max(rightMoney.steal_root, rightMoney.not_steal_root);
        return ans;

    }
};
// @lc code=end

