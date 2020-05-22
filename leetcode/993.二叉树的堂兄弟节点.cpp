/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

/*
很简单的一道题
一开始做的时候不用急着想把代码写优雅，想清楚要实现什么功能然后一个一个实现就好了。

我就是稳扎稳打的将计算深度和计算父亲值这两个需求都实现了，再看看标答学习一下有没有更优雅的写法。

Accepted
104/104 cases passed (4 ms)
Your runtime beats 83.01 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (10.8 MB)



https://leetcode-cn.com/problems/cousins-in-binary-tree/solution/er-cha-shu-de-tang-xiong-di-jie-dian-by-leetcode/

标答提供了这样的一种做法，挺简洁的：
1. 通过树的遍历，计算每个节点的深度和父节点的值
2. 使用hash表记录每一个节点的内容，键为val，值为父节点的值与深度。

*/

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
    bool isCousins(TreeNode* root, int x, int y) {
        int xd = getDepth(root, x);
        int xf = getFatherVal(root, x);
        int yd = getDepth(root, y);
        int yf = getFatherVal(root, y);
        if (xd >= 0 && yd >= 0 && xd == yd){
            if (xf != yf){
                return true;
            }
        }
        return false;
    }
    int getDepth(TreeNode* root, int val){
        if (root != NULL){
            if (root->val == val){
                return 0;
            }
            int lDepth = getDepth(root->left, val);
            int rDepth = getDepth(root->right, val);
            if (lDepth >= 0){
                return lDepth+1;
            } else if (rDepth >= 0){
                return rDepth+1;
            }
        }
        return -1;
    }
    int getFatherVal(TreeNode* root, int val){
        if (root != NULL){
            if (root->left != NULL && root->left->val == val){
                return root->val;
            }
            if (root->right != NULL && root->right->val == val){
                return root->val;
            }
            int lFather = getFatherVal(root->left, val);
            int rFather = getFatherVal(root->right, val);
            if (lFather > 0){
                return lFather;
            } else if (rFather > 0) {
                return rFather;
            }
        }
        return -1;
    }
};
// @lc code=end

