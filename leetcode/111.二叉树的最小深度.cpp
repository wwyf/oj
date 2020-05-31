/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

/*
思路
1. 递归、dfs、分解小问题（该树的最小深度=min(左树的最小深度, 右树的最小深度)+1）
2. bfs，一旦发现叶子结点马上返回深度(选择这种方法！)

```
Accepted
41/41 cases passed (16 ms)
Your runtime beats 57.37 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (17.5 MB)
```

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
struct QueueNode{
    TreeNode * root;
    int depth;
    QueueNode(TreeNode* root, int depth): root(root), depth(depth) {}

};
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<QueueNode> q;
        q.push(QueueNode(root, 1));
        while (!q.empty()){
            QueueNode cur = q.front();
            q.pop();
            if (cur.root == NULL) continue;
            TreeNode* left = cur.root->left;
            TreeNode* right = cur.root->right;
            int curDepth = cur.depth;
            if (left == NULL && right == NULL){
                return curDepth;
            } else {
                if (left != NULL) q.push(QueueNode(left, curDepth+1));
                if (right != NULL) q.push(QueueNode(right, curDepth+1));
            }
        }
        return 0;
    }
};
// @lc code=end

