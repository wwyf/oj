/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // vector< vector<int> > dp(s.size()+1, vector<int>(s.size()+1, 1));
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        // base case for dp[i][j]
        // 1. i = j, 1
        for (int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        for (int i = n-2; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1]; 
    }
};
// @lc code=end

