/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */


/*
Accepted
65/65 cases passed (288 ms)
Your runtime beats 5.14 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.8 MB)
*/

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        int res = 1;
        string s = "122";
        int i,k;
        // 这个模拟的方式很巧妙！
        for (i = 2, k = 1; i < n; i++, k=3-k){
            // 每循环一次加一组
            if (s[i] == '2'){
                s += to_string(k) + to_string(k);
            } else{
                res++;
                s += to_string(k);
            }
        }
        return res;

    }
};
// @lc code=end

