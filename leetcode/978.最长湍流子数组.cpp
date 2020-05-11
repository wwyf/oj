/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if (len <= 1) {
            return 1;
        }
        int dp[40001] = {0};
        int result = 1;
        dp[0] = 1;
        // 从第2个数开始遍历
        for (int i = 1; i < len; i++){
            if( A[i] == A[i-1]){
                // 相等
                dp[i] = 1;
            } else {
                // 不相等
                if (dp[i-1] == 1){
                    dp[i] = dp[i-1]+1;
                } else if  ( (A[i-2] < A[i-1] && A[i-1] > A[i]) || (  A[i-2] > A[i-1] && A[i-1] < A[i] )) {
                    dp[i] = dp[i-1]+1;
                } else {
                    dp[i] = 2;
                }
            }
            if (dp[i] > result){
                result = dp[i];
            }
        }
        return result;
    }
};
// @lc code=end

