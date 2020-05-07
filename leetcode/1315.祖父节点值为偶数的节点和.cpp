/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
 */

#include <vector>
using namespace std;
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start


class Solution {
public:
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if (root != NULL){
            if (root->left != NULL){
                preOrder(root->left->left, root->left, root);
                preOrder(root->left->right, root->left, root);
            }
            if (root->right != NULL){
                preOrder(root->right->left, root->right, root);
                preOrder(root->right->right, root->right, root);
            }
        }
        return sum;
    }
    void preOrder(TreeNode* root, TreeNode* dad, TreeNode* gdad){
        if (root != NULL){
            preOrder(root->left, root, dad);
            if(gdad != NULL && gdad->val % 2 == 0){
                sum += root->val;
            }
            preOrder(root->right, root, dad);
        }
    }
};
// @lc code=end

