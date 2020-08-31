/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

/*
2020-8-31 11:07:27
start
2020-8-31 11:26:51
end

```
Accepted

75/75 cases passed (12 ms)

Your runtime beats 92.83 % of cpp submissions

Your memory usage beats 34.36 % of cpp submissions (18.4 MB)
```

小结：
1. 我的做法是：后序遍历
2. 还有一种做法是：中序遍历，左中右，这种遍历在BST里面能够做到刚好按顺序遍历。就可以去检查了。
https://leetcode-cn.com/problems/validate-binary-search-tree/solution/zhong-xu-bian-li-qing-song-na-xia-bi-xu-miao-dong-/
2020-8-31 11:33:48
*/
#include <cassert>
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
    bool isValidBST(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        int root_max, root_min;
        return isValidBST(root, &root_max, &root_min);
    }
    bool isValidBST(TreeNode* root, int * maxVal, int * minVal){
        // 不允许在运行中出现这种情况
        if (root == NULL){
            assert(0);
            return true;
        }
        if (root->left == NULL && root->right == NULL){
            *maxVal = root->val;
            *minVal = root->val;
            return true;
        }
        int left_max, left_min;
        int right_max, right_min;
        if (root->left){
            if (!isValidBST(root->left, &left_max, &left_min)){
                return false;
            }
            if (left_max >= root->val){
                return false;
            }
        } else {
            left_min = root->val;
        }
        if (root->right){
            if (!isValidBST(root->right, &right_max, &right_min)){
                return false;
            }
            if (right_min <= root->val){
                return false;
            }
        } else {
            right_max = root->val;
        }
        // left_max < root->val < right_min
        *maxVal = right_max;
        *minVal = left_min;
        return true;
    }
};
// @lc code=end

