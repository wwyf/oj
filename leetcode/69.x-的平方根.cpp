/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

/*
看看题解：
https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/
https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
*/
// @lc code=start

class Solution {
public:
    int mySqrt(int x) {
       double l = 0;
       double r = x;
       double mid;
       while (int(l) != int(r)){
           mid = (l+r)/2;
           if (mid*mid > x){
               r = mid;
           } else{
               l = mid;
           }
       }
       return int(l);
    }
};
// @lc code=end

