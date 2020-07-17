/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> mynums(len+2);
        for (int i = 0; i < len; i++){
            mynums[i+1] = nums[i];
        }
        mynums[0] = 1;
        mynums[len+2-1] = 1;

        int mylen = len+2;

        vector< vector<int> > cache(mylen, vector<int>(mylen, 0));

        return dp(cache, mynums, 0, mylen-1);
    }
    int dp(vector< vector<int> > & cache, vector<int> & mynums, int left, int right){
        if (left + 1 == right){
            // 没有整数?
            return 0;
        }
        if (cache[left][right] > 0) return cache[left][right];

        int ans = 0;

        for (int i = left+1; i < right; i++){
            ans = max(ans, 
                mynums[left]*mynums[i]*mynums[right] 
                + dp(cache, mynums, left, i)
                + dp(cache, mynums, i, right));
        }
        cache[left][right] = ans;
        return ans;
    }
};
// @lc code=end

