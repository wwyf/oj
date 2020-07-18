/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        int ans = 0;
        int q;
        int i = 1;
        while (q = i*i,q<=n){
            ans++;
            i++;
        }
        return ans;
    }
    int bulbSwitch3(int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int sqrt_i = sqrt(i);
            if (sqrt_i*sqrt_i == i){
                // 是完全平方数
                ans += 1;
            }
        }
        return ans;
    }
    int bulbSwitch2(int n) {
        if (n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int ans = 0;
        int sqrt_n = sqrt(n);
        if (sqrt_n*sqrt_n == n){
            // 是完全平方数
            ans = 1;
        }
        return bulbSwitch(n-1) + ans;

    }
};
// @lc code=end

