/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.30%)
 * Likes:    3004
 * Dislikes: 94
 * Total Accepted:    366.6K
 * Total Submissions: 887.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
// dp[n] = max(dp[n-1], dp[n-2]+nums[n])
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0){
            return 0;
        }
        if (len == 1){
            return nums[0];
        }
        int cur, pre, pre2;
        pre = 0;
        pre2 = 0;
        for (int i = 0; i < len; i++){
            cur = max(pre2 + nums[i], pre);
            pre2 = pre;
            pre = cur;
        }
        return cur;
    }
};


