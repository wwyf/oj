/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.27%)
 * Likes:    3830
 * Dislikes: 364
 * Total Accepted:    588.6K
 * Total Submissions: 2.1M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// TODO: 还有其他解法可以尝试，看看leetcode的solution

class Solution1 {
// dp 解法
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length <= 1){
            return s;
        }
        if (length == 2){
            if (s[0] == s[1]){
                return s;
            }
            else {
                return s.substr(0,1);
            }
        }
        // 被没有清零害惨了！！
        int dp[1001][1001] = {0};
        memset(dp, sizeof(dp), 0);
        int maxlen = 0;
        int max_l_index = 0;
        for (int i = 0; i < length; i++){
            dp[i][i] = 1;
        }
        for (int i = 0; i < length-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
            }
        }
        // 填充dp表，按斜线填充
        for (int i = 0; i < length-2; i++){
            for (int j = 0; j < length-2-i; j++){
                if (s[j] == s[j+2+i]){
                    dp[j][j+2+i] = dp[j+1][j+1+i];
                }
            }
        }
        // 遍历dp表，寻找为1且长度最长的
        for (int i = 0; i < length; i++){
            for (int j = length-1; j >= i; j--){
                if (dp[i][j] && (j-i+1 > maxlen)){
                    maxlen = j-i+1;
                    max_l_index = i;
                }
            }
        }
        return s.substr((size_t)max_l_index, (size_t)maxlen);
    }
};

class Solution {
// 这个将找最大放在dp里面实现，会快一些。
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1){
            return s;
        }
        if (len == 2){
            if (s[0] == s[1]){
                return s;
            }
            else {
                return s.substr(0,1);
            }
        }   
        int dp[1001][1001] = {0};
        memset(dp, sizeof(dp), 0);
        int maxlen = 1;
        int max_l_index = 0;
        for (int i = 0; i < len; i++){
            dp[i][i] = 1;
        }
        for (int i = 0; i < len-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
                maxlen = 2;
                max_l_index = i;
            }
        }
        for (int i = 0; i < len-2; i++){
            for (int j = 0; j < len-2-i; j++){
                if (s[j] == s[j+2+i]){
                    dp[j][j+2+i] = dp[j+1][j+1+i];
                    if (dp[j][j+2+i] && 2+i+1 > maxlen){
                        maxlen = 2+i+1;
                        max_l_index = j;
                    }
                }
            }
        }
        return s.substr((size_t)max_l_index, (size_t)maxlen);
    }
};

// class Solution {
// // 这种解法做不出来
// public:
//     string longestPalindrome(string s) {
//         int len = s.size();
//         if (len <= 1){
//             return s;
//         }
//         int maxindex = 0;
//         int maxlen = 1;
//         int dp[1001];
//         // memset(dp, sizeof(dp), 0);
//         dp[0] = 1;
//         for (int i = 1 ; i < len ; i++){
//             int offset = dp[i-1]+1;
//             dp[i] = 1;
//             // 新加一个字母，如果前面是回文串，而且还能与回文串前面的配对的话，就能加两个。
//             if (i-offset >= 0 && s[i-offset] == s[i]){
//                     dp[i] = dp[i-1]+2;
//             }
//             // 如果不能加两个，那再看看弱一点的情况，在某些特殊的情况下，回文串能增加1
//             // 特殊的情况是指：字符相同
//             else if (s[i] == s[i-1]){
//                 int isSame = 1;
//                 for (int j = i-1; j >= (i-dp[i-1]); j--){
//                     if (s[j] != s[i-1]){
//                         isSame = 0;
//                     }
//                 }
//                 if (isSame){
//                     dp[i] = dp[i-1]+1;
//                 }
//             }
//             if (dp[i] > maxlen){
//                 maxlen = dp[i];
//                 maxindex = i;
//             }
//         }
//         return s.substr((size_t)maxindex-dp[maxindex]+1, (size_t)maxlen);
//     }
// };


// int main(){
//     string s;
//     cout << "input s:";
//     cin >> s;
//     cout << Solution().longestPalindrome(s);
// }

