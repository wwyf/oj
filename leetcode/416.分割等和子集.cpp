/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size();
        if ( (sum & 1) == 1){ 
            // 确保是偶数
            return false;
        }
        int targetSum = sum/2;
        vector<bool> dp(targetSum+1, false) ;
        // base case
        dp[0] = true;
        for (int i = 1; i <= len; i++){
            for (int j = targetSum; j >= 1; j--){
                int left = j - nums[i-1];  
                if (left >= 0){
                    dp[j] = dp[j] | dp[left];
                }
            }
        }
        return dp[targetSum];
    }
};
// @lc code=end

