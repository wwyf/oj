/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

/*
方法一：递归/DFS

太简单了，只要能够将问题分解，然后递归就可以了
这里也不存在重复使用结果的问题，不必动态规划
另外是否可以将这个改成不带递归的呢？直接用迭代可以吗？感觉比较麻烦。

Accepted
39/39 cases passed (8 ms)
Your runtime beats 93.12 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (16.7 MB)

另外，在递归前加一个判断能够少一层递归，速度会快一些。上面的结果是保留判断的，下面的结果是去掉额外判断的。
Accepted
39/39 cases passed (12 ms)
Your runtime beats 71.47 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (16.8 MB)

方法二：迭代/BFS
使用BFS我也想过了，我没想到的一点是，那个队列里存的数据结构我可以加上一项『深度』。

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int leftMax = 0;
        int rightMax = 0;
        if (root->left != NULL ) {
            leftMax = maxDepth(root->left);
        }
        if (root->right != NULL){
            rightMax = maxDepth(root->right);
        }
        int allMax = (leftMax > rightMax)? leftMax : rightMax;
        return allMax+1;
    }
};
// @lc code=end

