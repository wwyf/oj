/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// 1. 用模拟的方法(很麻烦的)
// 2. 在理解题目的行为后，进行简化(如下)

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        int s,e,count;
        s = 1;
        e = n;
        int d = 1;
        int ifleft = 1;
        while(s < e){
            count = (e-s)/d + 1;
            if (ifleft){
                s += d;
                if ( count%2 == 1 ){
                    e -= d;
                }
            } else {
                e -= d;
                if ( count%2 == 1 ){
                    s += d;
                }
            }
            ifleft = 1 - ifleft;
            d *= 2;
        }
        return s;
    };
};
// @lc code=end

