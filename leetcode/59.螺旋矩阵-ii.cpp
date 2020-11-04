/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int remains = n*n;
        int cur = 1;
        int min_row = 0;
        int max_row = n-1;
        int min_col = 0;
        int max_col = n-1;
        int r = 0;
        int c = 0;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while(cur <= remains){
            for (r = min_row, c = min_col; c <= max_col && cur <= remains; c++){
                ans[r][c] = cur;
                cur++;
            }
            min_row++;
            for (r = min_row, c = max_col; r <= max_row && cur <= remains; r++){
                ans[r][c] = cur;
                cur++;
            }
            max_col--;
 
            for (r = max_row, c = max_col; c >= min_col && cur <= remains; c--){
                ans[r][c] = cur;
                cur++;
            }
            max_row--;
 
            for (r = max_row, c = min_col; r >= min_row && cur <= remains; r--){
                ans[r][c] = cur;
                cur++;
            }
            min_col++;
        }
        return ans;
    }
};
// @lc code=end

