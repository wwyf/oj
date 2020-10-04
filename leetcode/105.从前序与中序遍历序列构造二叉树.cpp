/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    unordered_map<int,int> indexes;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            indexes[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int p_start, int p_end, vector<int> & inorder, int i_start, int i_end){
        if (p_end < 0){
            return NULL;
        }
        if (p_start > p_end){
            return NULL;
        }
        int root_val = preorder[p_start];
        TreeNode * root = new TreeNode(preorder[p_start]);
        TreeNode * left = NULL;
        TreeNode * right = NULL;

        if (p_start == p_end && i_start == i_end){
            return root;
        }
        // find root in inorder
        int root_inorder_index = indexes[root_val];
        int left_tree_length = root_inorder_index-i_start;

        int left_inorder_start = i_start;
        int left_inorder_end = root_inorder_index-1;
        int left_preorder_start = p_start+1;
        int left_preorder_end = p_start+left_tree_length;

        int right_inorder_start = root_inorder_index+1;
        int right_inorder_end = i_end;
        int right_preorder_start = p_start+left_tree_length+1;
        int right_preorder_end = p_end;

        left = buildTree(preorder, left_preorder_start, left_preorder_end, inorder, left_inorder_start, left_inorder_end);
        right = buildTree(preorder, right_preorder_start, right_preorder_end, inorder, right_inorder_start, right_inorder_end);

        root->left = left;
        root->right = right;
        return root;
    }
};
// @lc code=end

int main(){
    vector<int> a = {1,2};
    vector<int> b = {1,2};
    Solution().buildTree(a,b);
}