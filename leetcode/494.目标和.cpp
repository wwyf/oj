/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int nums_length = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000){
            return 0;
        }
        nums_length = nums.size();
        int dp[21][2002] = {0};
        dp[0][0+1000] = 1;
        for (int i = 1; i <= nums_length; i++){
            for (int j = -1000; j <= 1000; j++){
                int l = j-nums[i-1];
                int r = j+nums[i-1];
                if (-1000 <= l && l <= 1000 && dp[i-1][l+1000] > 0){
                    dp[i][j+1000] += dp[i-1][l+1000];
                }
                if (-1000 <= r && r <= 1000 && dp[i-1][r+1000] > 0){
                    dp[i][j+1000] += dp[i-1][r+1000];
                }
            }
        }
        return dp[nums_length][S+1000];
    }
};
// @lc code=end




