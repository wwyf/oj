/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size(), 1);
        for (int i = nums.size()-2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++){
            suffix[i] = prefix * suffix[i];
            prefix *= nums[i];
        }
        return suffix;
    }
};
// @lc code=end

