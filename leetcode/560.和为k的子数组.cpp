/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 0){
            return 0;
        }
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
// @lc code=end

