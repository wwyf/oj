/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int MAX = 301;
        int dp[MAX][MAX] = {0};
        int n = matrix.size();
        if (n <= 0){
            return 0;
        }
        int m = matrix[0].size();
        if (m <= 0){
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
// @lc code=end

