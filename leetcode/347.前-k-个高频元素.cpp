/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (auto n : nums){
            cnts[n]++;
        }
        unordered_map<int, vector<int>> cnts2num;
        for (auto p : cnts){
            cnts2num[p.second].emplace_back(p.first);
        }
        int n = nums.size();
        int ans_count = 0;
        vector<int> ans;
        for (int i = n; ans_count < k && i >= 1; i--){
            if (cnts2num.find(i) != cnts2num.end()){
                auto & this_nums = cnts2num[i];
                ans.insert(ans.end(), this_nums.begin(), this_nums.end());
                ans_count += this_nums.size();
            }
        }
        return ans;

    }
};
// @lc code=end

