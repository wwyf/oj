/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (35.57%)
 * Likes:    1047
 * Dislikes: 38
 * Total Accepted:    129.5K
 * Total Submissions: 363.9K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */
/* 
环形的话，那么第一个数与最后一个数一定只能拿其中一个
那么不妨直接计算 [0, n-1] 到 [1, n] 这两个可能能抢到的最大值。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0){
            return 0;
        }
        if (len == 1){
            return nums[0];
        }
        return max(rob(nums, 0, len-1), rob(nums, 1, len));
    }
    int rob(vector<int>& nums, int first, int second){
        // len >= 2
        int cur, pre, pre2;
        pre = 0;
        pre2 = 0;
        int len = nums.size();
        for (int i = first; i < second; i++){
            cur = max(pre2+nums[i], pre);
            pre2 = pre;
            pre = cur;
        }
        return cur;
    }
};

