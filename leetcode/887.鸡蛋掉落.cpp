/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

#include <cmath>
// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        if (K == 1){
            return N;
        }
        if (N == 1){
            return 1;
        }
        return 1+superEggDrop(K-1, (N+1)/2);
    }
};
// @lc code=end

