/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */


/*
Accepted

31/31 cases passed (0 ms)

Your runtime beats 100 % of cpp submissions

Your memory usage beats 100 % of cpp submissions (5.8 MB)
*/

// @lc code=start
class Solution {
public:
    int cache[50];
    Solution(){
        for (int i = 0; i < 50; i++){
            cache[i] = -1;
        }
    }
    int fib(int N) {
        if (N == 0){
            return 0;
        }
        if (N == 1){
            return 1;
        }
        if (cache[N] != -1){
            return cache[N];
        }
        cache[N] = fib(N-1)+fib(N-2);
        return cache[N];

    }
};
// @lc code=end

