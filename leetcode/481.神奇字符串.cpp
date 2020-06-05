/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        int res = 0;
        string s = "122";
        int i,k;
        // 这个模拟的方式很巧妙！
        for (i = 2, k = 1; i < n; i++, k=3-k){
            // 每循环一次加一组
            if (s[i] == '2'){
                s += to_string(k) + to_string(k);
            } else{
                s += to_string(k);
            }
        }
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                res++;
            }
        }
        return res;

    }
};
// @lc code=end

