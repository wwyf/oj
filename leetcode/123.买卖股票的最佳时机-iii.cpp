/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size(); 
        int max_k = 2;
        int dp[n][max_k+1][2]; ::memset(dp, 0, sizeof(dp));

        for(int i=0; i < n; i++) { 
    
            for(int k=1; k <= max_k; ++k) { 
                
                if(i==0) { 
                    dp[0][k][0] =0;
                    dp[0][k][1] =-prices[0];
                    continue;
                }

                dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1]   + prices[i]);
                dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
               
            }
        }

        return dp[n-1][max_k][0];
    }
};
// @lc code=end

