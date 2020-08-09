/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++){
            for (int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

