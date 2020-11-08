/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
        int len = nums.size();
        for (int i = 0; i < len; i++){
            set.insert(nums[i]);
        }
        for (int i = 1; i < INT_MAX; i++){
            if (set.find(i) == set.end()){
                return i;
            }
        }
        return 0;

    }
};
// @lc code=end

