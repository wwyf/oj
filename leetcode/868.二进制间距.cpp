/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

/*
    很简单的一道题，冷静点写就好了
看了答案，有以下收获：
1. 看到二进制表示，应该要想到可以用位运算来实现 (N>>I)&1 就可以得到末位的比特值，不需要手动计算，太傻了。
2. 我的实现中，仅仅使用了数字的值（0/1），其实可以使用1的索引来计算，记录上一次碰到的1的索引，当再次碰到1时，如果上一次不存在，就更新到上一次中，否则算出这次1与上次1的距离，并将这一次的索引更新到上一次中。


*/

#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int binaryGap(int N) {
        if (N <= 2){
            return 0;
        }
        int ans = 0;
        int temp_ans = 0;
        int status = 0; // 0:init 1:counting
        // transform to  bianry
        while (N > 0){
            int cur = N % 2;
            N = (N-cur)/2;
            // cur 变量 相当于在遍历binary
            if (status == 0){
                if (cur == 0){
                    continue;
                }
                if (cur == 1){
                    status = 1;
                    temp_ans = 1;
                }
            } else if (status == 1){
                if (cur == 0){
                    temp_ans ++;
                }
                if (cur == 1){
                    ans = max(ans, temp_ans);
                    temp_ans = 1;
                }
            }
        }

        return ans;


    }
};
// @lc code=end

