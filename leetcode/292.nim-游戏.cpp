/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

/*

思路虽然很简单，但是其中可以用到的dp知识可以学学！！
https://leetcode-cn.com/problems/nim-game/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-54/

*/

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
// @lc code=end

