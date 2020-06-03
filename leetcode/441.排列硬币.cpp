/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

/*
太简单了，用二次方程求解就好
*/

#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        // 使用long long避免溢出
        // long long tn = n;
        // return int((sqrt(1+8*tn)-1)/2);
        // 直接使用double避免溢出
        // return int((sqrt(1+8*double(n))-1)/2);
        // 为了避免int溢出，特别注意！要用1.0/2，才能够得到double，否则1/2的话直接就是0了
        return int((2*sqrt(1.0/8+n/2.0)-1.0/2));
    }
};
// @lc code=end

