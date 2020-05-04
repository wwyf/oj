/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 */


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N <= 0 || N == 2 || N % 2 == 0) {
            return vector<TreeNode*>{};
        }
        // N <= 20
        vector<TreeNode*> cached[30];
        // init N == 1
        TreeNode* root = new(TreeNode){0};
        cached[1] = vector<TreeNode*>{root};

        // N 一定是奇数
        for(int k = 3; k <= N; k+=2){
            for (int i = 1; i <= k-2; i+=2){
                auto leftTrees = cached[i];
                auto rightTrees = cached[k-i-1];
                for (auto l : leftTrees){
                    for (auto r : rightTrees){
                        TreeNode* root = new(TreeNode){0};
                        root->left = l;
                        root->right = r;
                        cached[k].push_back(root);
                    }
                }
            }
        }
        return cached[N];
    }
};
// @lc code=end

