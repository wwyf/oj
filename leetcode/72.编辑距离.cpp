/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        // dp[i][j] : work1 i, work2 j

        // base case for dp[0][j] and dp[i][0]
        dp[0][0] = 0;
        for (int i = 1; i <= word1.size(); i++){
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.size(); i++){
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++){
                if (word1[i-1] == word2[j-1]){ // BUG 注意索引！
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
