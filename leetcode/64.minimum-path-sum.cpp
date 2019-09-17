/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    1627
 * Dislikes: 43
 * Total Accepted:    260.9K
 * Total Submissions: 536.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0){
            return 0;
        }
        int w = grid[0].size();
        int dp[h+1][w+1];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if (i == 0){
                    if (j == 0){
                        dp[i][j] = grid[0][0];
                    }
                    else{
                        dp[i][j] = grid[i][j] + dp[i][j-1];
                    }
                    continue;
                }
                else if (j == 0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                    continue;
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[h-1][w-1];
    }
};

