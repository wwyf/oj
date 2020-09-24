/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0){
            return false;
        }
        int dp[500] = {0};
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++){
            for (auto word : wordDict){
                int word_size = word.size();
                if (i >= word_size && s.substr(i-word_size, word_size) == word){
                    dp[i] = dp[i-word_size];
                }
                if (dp[i]){
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

