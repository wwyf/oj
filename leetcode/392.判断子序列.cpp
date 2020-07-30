/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
/*
2020-7-30 08:55:20
2020-7-30 09:01:51
Accepted

15/15 cases passed (0 ms)

Your runtime beats 100 % of cpp submissions

Your memory usage beats 40.4 % of cpp submissions (6.5 MB)


看看标答：
https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
实现得比我优雅，值得学习，双指针。

关于那个后续挑战，使用DP解决：
关键思路：将t中的信息先提前预处理出来，避免重复运算。

>考虑前面的双指针的做法，我们注意到我们有大量的时间用于在 t 中找到下一个匹配字符。
>这样我们可以预处理出对于 t 的每一个位置，从该位置开始往后每一个字符第一次出现的位置。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#TODO 暂时想懂了会写了，等下次忘记了我再来实现它

*/

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ans = true;
        int ti = 0;
        for (auto c : s){
            // whether c is in s
            while(ti < t.size() && t[ti] != c){
                ti++;
            }
            if (ti >= t.size() || t[ti] != c){
                ans = false;
                break;
            }
            // t[ti] == c
            ti++;
        }
        return ans;
    }
};
// @lc code=end

