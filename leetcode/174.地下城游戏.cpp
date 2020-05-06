/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int nr = dungeon.size();
        int nc = dungeon[0].size();
        // 从(i,j)走向右下角所需要的最小生命值
        int dp[500][500] = {99999999};
        for (int i = nr-1; i >= 0; i--){
            for (int j = nc-1; j>= 0; j--){
                if (i == nr-1 && j == nc-1){
                    dp[i][j] = max(1, 1-dungeon[i][j]);
                } else if (i == nr-1) {
                    dp[i][j] = max(1, dp[i][j+1]-dungeon[i][j]);
                } else if (j == nc-1){
                    dp[i][j] = max(1, dp[i+1][j]-dungeon[i][j]);
                } else{
                    dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

