/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// 
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int dp[50][50];
//         memset(dp, 0, sizeof(int)*50*50);
//         dp[0][0] = 1;
//         // dp[0][?] = 0
//         for (int i = 1; i <= p.size(); i++){
//             for (int j = 0; j <= s.size(); j++){
//                 if (p[i] != '*' && p[i] != '.'){
//                     dp[i][j] = (p[i] == s[j]) & dp[i-1][j-1];
//                 } else if (p[i] == '.'){
//                     dp[i][j] = dp[i-1][j-1];
//                 } else if (p[i] == '*'){
//                     dp[i][j] |= dp[i-2][j];
//                     if (p[i-1] == '.' || (p[i-1] != '.' && p[i-1] == s[j])){
//                         dp[i][j] |= dp[i][j-1];
//                     }
//                 }
//             }
//         }
//         return dp[p.size()][s.size()];
//     }
// };
// @lc code=end

