/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (55.86%)
 * Likes:    3247
 * Dislikes: 196
 * Total Accepted:    389.1K
 * Total Submissions: 683.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#include <vector>
#include <string>
using namespace std;

// TODO: 没想到怎么证明：

/*
暴力：生成所有的排列组合然后一一筛选。
*/
class Solution1 {
public:
    // 暴力！
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<string> all = generateAll(2*n);
        int len = all.size();
        for (int i = 0; i < len; i++){
            if (valid(all[i])){
                ans.push_back(all[i]);
            }
        }
        return ans;
    }
    // 生成所有的序列
    vector<string> generateAll(int n){
        vector<string> ans;
        if (n == 1){
            ans.push_back("(");
            ans.push_back(")");
            return ans;
        }
        vector<string> extra = generateAll(n-1);
        int len = extra.size();
        for (int i = 0; i < len; i++){
            ans.push_back("(" + extra[i]);
            ans.push_back(")" + extra[i]);
        }
        return ans;
    }
    // 这种检验的方法值得学习，暂时没想到怎么证明这种方法是对的
    bool valid(string s){
        int len = s.size();
        int balance = 0;
        for (int i = 0; i < len; i++){
            if (s[i] == '('){
                balance ++;
            }
            else if (s[i] == ')'){
                balance --;
            }
            if(balance < 0){
                return false;
            }
        }
        if (balance != 0){
            return false;
        }
        return true;
    }
};

/*
回溯：
*/
class Solution2 {
public:
    // 暴力！
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateAllValid(ans, "", 0,0,n);
        return ans;
    }
    void generateAllValid(vector<string> & ans, string s, int left, int right, int n){
    // 通过回溯的方法生成所有符合要求的字符串
        if( s.size() == 2*n ){
            ans.push_back(s);
        }
        if (left < n ){
            generateAllValid(ans, s+"(", left+1, right, n);
        }
        // 可以这样想，不管我以何种顺序放入(,)，只要(的数量比)少，那么前面的每个)都能找到对应的(，并且我再加入的这个)也能找到对应的(
        if (left > right){
            generateAllValid(ans, s+")", left, right+1, n);
        }
    }
};


/*
√ Accepted
  √ 8/8 cases passed (4 ms)
  √ Your runtime beats 88.08 % of cpp submissions
  √ Your memory usage beats 90.08 % of cpp submissions (13.5 MB)
*/
class Solution {
    public:
    vector<string> generateParenthesis(int n){
        // 想一想如何划分子任务
        vector<string> ans;
        if (n == 0){
            // 重要！
            ans.push_back("");
            return ans;
        }
        if (n == 1){
            ans.push_back("()");
            return ans;
        }
        for (int i = 0; i < n; i++){
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n-1-i);
            int left_len = left.size();
            int right_len = right.size();
            for (int j = 0; j < left_len; j++){
                for (int k = 0; k < right_len; k++){
                    ans.push_back("("+left[j]+")"+right[k]);
                }
            }
        }
        return ans;
    }

};

