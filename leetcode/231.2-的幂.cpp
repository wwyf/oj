/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int num = n;
        int count = 0;
        while(num){
            if (num & 1 == 1){
                count++;
            }
            num = num>>1;
        }
        if (count == 1){
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

