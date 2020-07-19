/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[9996]; // 最小了
        // vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++){
            // 寻找所有可能中最小的那个，如果没有修改，那就是-1.
            int minCount = INT_MAX;
            for (int j = 0; j < coins.size(); j++){
                if (coins[j] <= i){
                    if (dp[i - coins[j]] >= 0){
                        minCount = min(minCount, dp[i-coins[j]]);
                    }
                }
            }
            if (minCount == INT_MAX){
                dp[i] = -1;
            } else {
                dp[i] = minCount+1;
            }
        }
        return dp[amount];
    }
};
// @lc code=end

