/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class FindElements {
public:
    TreeNode * root;
    set<int> treeVals;

    FindElements(TreeNode* root) {
        root->val = 0;
        recoverTree(root);
        this->root = root;
    }
    void recoverTree(TreeNode* root){
        if (root != NULL){
            treeVals.insert(root->val);
            if (root->left != NULL){
                root->left->val = 2*root->val+1;
                recoverTree(root->left);
            }
            if (root->right != NULL){
                root->right->val = 2*root->val+2;
                recoverTree(root->right);
            }
        }
    }
    
    bool find(int target) {
        return treeVals.find(target) != treeVals.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

