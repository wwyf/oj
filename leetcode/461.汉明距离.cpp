/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

/*
https://leetcode-cn.com/problems/hamming-distance/solution/yi-ming-ju-chi-by-leetcode/
表达有一些骚操作。

> 布赖恩·克尼根位计数算法的基本思想
> 当我们在 number 和 number-1 上做 AND 位运算时，原数字 number 的最右边等于 1 的比特会被移除


*/

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x||y){
            if ((x & 1)!=(y & 1)){
                ans++;
            }
            x = x>>1;
            y = y>>1;
        }
        return ans;
    }
};
// @lc code=end

