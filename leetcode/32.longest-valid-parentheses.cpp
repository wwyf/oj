/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.28%)
 * Likes:    2236
 * Dislikes: 103
 * Total Accepted:    214K
 * Total Submissions: 814.6K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
#include <cstring>
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        int max_left = 0;
        int len = s.size();
        if (len <= 1){
            return 0;
        }
        int dp[len];
        memset(dp, 0, len*sizeof(int));
        if (s[0] == '(' && s[1] == ')') {
            dp[1] = 2;
            max_len = 2;
        }
        for (int i = 2; i < len; i++){
            if (s[i-1] == '(' && s[i] == ')'){
                dp[i] = dp[i-2] + 2;
            }
            if (s[i-1] == ')' && s[i] == ')' && i-dp[i-1]-1 >= 0 &&  s[i-dp[i-1]-1] == '('){
                if (i-dp[i-1]-2 >= 0){
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                }
                else{
                    dp[i] = dp[i-1] + 2;
                }
            }
            if (dp[i] >= max_len){
                max_len = dp[i];
                max_left = i;
            }
        }
        return max_len;
    }
};

/* approach 4 */
class Solution {
    public: 
    int longestValidParentheses(string s){
        int left = 0;
        int right = 0;
        int len = s.size();
        int max_len = 0;
        for (int i = 0; i < len; i++){
            if (s[i] == '('){
                left++;
            }
            else {
                right++;
            }
            if (left == right){
                max_len = max(max_len, 2*left);
            }
            else if (left < right){
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for (int i = len-1; i >= 0; i--){
            if (s[i] == '('){
                left++;
            }
            else {
                right++;
            }
            if (left == right){
                max_len = max(max_len, 2*left);
            }
            else if (left > right){
                left = 0;
                right = 0;
            }
        }
        return max_len;
    }
};