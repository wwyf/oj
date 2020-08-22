/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        for (int i = 1; i <= length; i++){
            int cur_size = ans.size();
            for (int j = 0; j < cur_size; j++){
                auto n = ans[j];
                n.push_back(nums[i-1]);
                ans.push_back(n);
            }
        }
        return ans;
    }
};
// @lc code=end

