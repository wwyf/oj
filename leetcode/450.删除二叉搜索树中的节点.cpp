/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */
#include <iostream>
#include <string>

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

const int LEFT = 1;
const int RIGHT = 2;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode rootPar{0};
        rootPar.left = root;

        // find
        // init
        TreeNode * targetPar = &rootPar;
        TreeNode * targetNode = targetPar->left;
        int direct = LEFT;
        while(targetNode != NULL && targetNode->val != key){
            // std::cout << targetNode->val << std::endl;
            targetPar = targetNode;
            if (targetNode->val < key){
                targetNode = targetNode->right;
                direct = RIGHT;
            } else {
                targetNode = targetNode->left;
                direct = LEFT;
            }
        }
        if (targetNode == NULL){
            return root;
        }
        deleteNode(targetPar, direct, targetNode);

        return  rootPar.left;
    }
    // 可以只写方向
    void deleteNode(TreeNode * parent, int direct , TreeNode * targetNode){
        if (targetNode->left == NULL && targetNode->right == NULL){
            if (direct == LEFT) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            // delete targetNode;
            return ;
        }
        if (targetNode->left != NULL){
            // 在左子树中找到最右节点，并将最右节点赋值到targetNode，然后删除最右节点
            TreeNode * stPar = targetNode->left;
            TreeNode * stRight = stPar;
            while(stRight->right != NULL){
                stPar = stRight;
                stRight = stRight->right;
            }
            // stRight可能和stPar相等
            if (stRight == stPar){
                // 如果相等说明可以直接将stPar接到parent上
                stPar->right = targetNode->right;
                if (direct == LEFT){
                    parent->left = stPar;
                } else {
                    parent->right = stPar;
                }
                // delete targetNode;
            } else {
                // 如果不相等，那就将最右节点赋值到targetNode，然后删掉stRight
                targetNode->val = stRight->val;
                deleteNode(stPar, RIGHT, stRight);
            }
        } else if (targetNode->right != NULL){
            // 在右子树中找到最左节点，并将最左节点赋值到targetNode，然后删除最右节点
            TreeNode * stPar = targetNode->right;
            TreeNode * stLeft = stPar;
            while(stLeft->left != NULL){
                stPar = stLeft;
                stLeft = stLeft->left;
            }
            // stLeft可能和stPar相等
            if (stLeft == stPar){
                // 如果相等说明可以直接将stPar接到parent上
                stPar->left = targetNode->left;
                if (direct == LEFT){
                    parent->left = stPar;
                } else {
                    parent->right = stPar;
                }
                // delete targetNode;
            } else {
                // 如果不相等，那就将最左节点赋值到targetNode，然后删掉stLeft
                targetNode->val = stLeft->val;
                deleteNode(stPar, LEFT, stLeft);
            }
        }

    }
};

// @lc code=end

int main(){
    TreeNode root(5);
    TreeNode n3(3);
    TreeNode n6(6);
    TreeNode n2(2);
    TreeNode n4(4);
    TreeNode n7(7);
    root.left = &n3;
    root.right = &n6;
    n3.left = &n2;
    n3.right = &n4;
    n6.right = &n7;
    Solution{}.deleteNode(&root, 3);

    // TreeNode root(5);
    // TreeNode n3(3);
    // TreeNode n6(6);
    // TreeNode n2(2);
    // TreeNode n4(4);
    // TreeNode n7(7);
    // root.left = &n3;
    // root.right = &n6;
    // n3.left = &n2;
    // n3.right = &n4;
    // n6.right = &n7;
    // Solution{}.deleteNode(&root, 3);
}

