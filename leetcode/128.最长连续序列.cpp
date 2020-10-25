/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 1;
        unordered_set<int> s;
        for (auto i : nums){
            s.insert(i);
        }
        int len = nums.size();
        for (int i = 0; i < len; i++){
            if (nums[i] > INT_MIN && nums[i] < INT_MAX-1 && s.find(nums[i]-1) == s.end() ){
                int cur_num = nums[i];
                while(s.find(cur_num+1) != s.end()){
                    cur_num++;
                }
                ans = max(ans, cur_num - nums[i] + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

