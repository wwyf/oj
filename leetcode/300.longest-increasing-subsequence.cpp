/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.40%)
 * Likes:    2967
 * Dislikes: 69
 * Total Accepted:    259.2K
 * Total Submissions: 625.7K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1){
            return len;
        }
        int dp[len+1];
        for (int i = 0; i <= len; i++){
            dp[i] = 1;
        }
        for (int i = 2; i <= len; i++){
            for (int j = 1; j < i; j++){
                if (nums[i-1] > nums[j-1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= len; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

