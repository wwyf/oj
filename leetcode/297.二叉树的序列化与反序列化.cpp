/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include <iostream>
#include <string>
#include <vector>
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
class Codec {
public:
    long long getTreeDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        return max(getTreeDepth(root->left), getTreeDepth(root->right))+1;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr){
            return "[]";
        }
        long long depth = getTreeDepth(root);
        long long len = (1 << depth) - 1;
        vector<string> lists(len);
        for (long long i = 0; i < len; i++){
            lists[i] = "null";
        }
        dfs_filfull(lists, root, 0);
        string ans;
        ans += "[";
        ans += lists[0];
        for (long long i = 1; i < len; i++){
            ans += ",";
            ans += lists[i];
        }
        ans += "]";
        // cout << ans << endl;
        return ans;
    }

    void dfs_filfull(vector<string> & lists, TreeNode * root, long long  index){
        if (root == nullptr){
            return;
        }
        lists[index] = to_string(root->val);
        dfs_filfull(lists, root->left, 2*index+1);
        dfs_filfull(lists, root->right, 2*index+2);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 2){
            return nullptr;
        }
        string data2 = data.substr(1, data.size()-2);
        vector<string> lists;
        long long string_len = data2.size();
        long long ep = 0;
        while(ep < string_len){
            long long char_count = 0;
            while(ep+char_count < string_len && data2[ep+char_count] != ','){
                char_count++;
            }
            lists.push_back(data2.substr(ep, char_count));
            ep += char_count+1;
        }

        TreeNode * root;
        root = dfs_create(lists, 0);



        return root;
        
    }
    TreeNode* dfs_create(vector<string> & lists, long long  index){
        if (index >= lists.size() || lists[index] == "null") return nullptr;
        auto root = new TreeNode(stoi(lists[index]));
        root->left = dfs_create(lists, 2*index+1);
        root->right = dfs_create(lists, 2*index+2);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

