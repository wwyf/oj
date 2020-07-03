/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        int dp[1001][1001];
        for (int i = 0; i < len1; i++){
            dp[i][0] = 0;
        }
        for (int i = 0; i < len2; i++){
            dp[0][i] = 0;
        }
        for (int i = 0; i < len1; i++){
            for (int j = 0; j <len2; j++){
                if (text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

