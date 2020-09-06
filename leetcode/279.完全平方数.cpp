/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */


#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n == 0){
            return 0;
        }
        int dp[10001] = {0};
        for (int i = 0; i <= n; i++){
            dp[i] = i;
        }
        for (int i = 1; i <= n; i++){
            int q = 1;
            while(q*q <= i){
                dp[i] = min(dp[i-q*q]+1, dp[i]);
                q++ ;
            }
        }
        return dp[n];
    }
};
// @lc code=end

