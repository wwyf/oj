/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, int cur){
        if (cur == nums.size()){
            ans.push_back(nums);
            return;
        }
        int nums_len = nums.size();
        for (int i = cur; i < nums_len; i++){
            swap(nums[cur], nums[i]);
            backtrack(nums, cur+1);
            swap(nums[cur], nums[i]);
        }
    }
};
// @lc code=end

