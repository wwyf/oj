/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int min_row = 0;
        int max_row = matrix.size()-1;
        if (max_row < 0){
            return vector<int>{};
        }
        int min_col = 0;
        int max_col = matrix[0].size()-1;
        int r = 0;
        int c = 0;
        int remains = (max_row+1)*(max_col+1);
        vector<int> ans;
        while(remains >= 1){
            for (r = min_row, c = min_col; c <= max_col && remains >= 1; c++){
                ans.push_back(matrix[r][c]);
                remains--;
            }
            min_row++;

            for (r = min_row, c = max_col; r <= max_row && remains >= 1; r++){
                ans.push_back(matrix[r][c]);
                remains--;
            }
            max_col--;

            for (r = max_row, c = max_col; c >= min_col && remains >= 1; c--){
                ans.push_back(matrix[r][c]);
                remains--;
            }
            max_row--;

            for (r = max_row, c = min_col; r >= min_row && remains >= 1; r--){
                ans.push_back(matrix[r][c]);
                remains--;
            }
            min_col++;
        }
        return ans;

    }
};
// @lc code=end

