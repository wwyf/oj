/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0){
            return vector<int>{0};
        }
        if (n == 1){
            return vector<int>{0,1};
        }
        // n >= 2
        vector<int> next_gray_code = grayCode(n-1);
        int len_next_gray_code = next_gray_code.size();
        // 2^(n-1)
        int padding = (1 << (n-1));
        for (int i = len_next_gray_code-1; i >= 0; i--){
            next_gray_code.push_back(padding+next_gray_code[i]);
        }
        return next_gray_code;
    }
};
// @lc code=end

