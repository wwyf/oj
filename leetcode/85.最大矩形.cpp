/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int y_len = matrix.size();
        if (y_len == 0) return 0;
        int x_len = matrix[0].size();
        int heights[1000] = {0};
        int lefts[1000] = {0};
        int rights[1000] = {x_len};
        for (int i = 0; i < 1000; i++){
            rights[i] = x_len;
        }
        int ans = 0;
        for (int i = 0; i < y_len; i++){
            int cur_left = 0;
            int cur_right = x_len;
            for (int j = 0; j < x_len; j++){
                if (matrix[i][j] == '1'){
                    heights[j] = heights[j]+1;
                }else{
                    heights[j] = 0;
                }
            }

            for (int j = 0; j < x_len; j++){
                if (matrix[i][j] == '1'){
                    lefts[j] = max(lefts[j], cur_left);
                }else{
                    cur_left = j+1;
                    lefts[j] = 0;
                }
            }

            for (int j = x_len-1; j >= 0; j--){
                if (matrix[i][j] == '1'){
                    rights[j] = min(rights[j], cur_right);
                }else{
                    cur_right = j;
                    rights[j] = x_len;
                }
            }

            for (int j = 0; j < x_len; j++){
                // cout << heights[j] << rights[j] << lefts[j] << endl;
                ans = max(ans, heights[j]*(rights[j]-lefts[j]));
            }
        }
        return ans;

    }
};
// @lc code=end

