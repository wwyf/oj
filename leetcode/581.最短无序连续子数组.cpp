/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = INT_MAX;
        int r = 0; 
        int len = nums.size();
        stack<int> s;
        for (int i = 0; i < len; i++){
            while(!s.empty() && nums[s.top()] > nums[i]){
                auto pop_i = s.top(); s.pop();
                l = min(l, pop_i);
            }
            s.push(i);
        }
        stack<int> s2;
        for (int i = len-1; i >=0; i--){
            while(!s.empty() && nums[s.top()] < nums[i]){
                auto pop_i = s.top(); s.pop();
                r = max(r, pop_i);
            }
            s.push(i);
        }
        if (r-l < 0){
            return 0;
        }

        return  r-l+1;

    }
};
// @lc code=end

