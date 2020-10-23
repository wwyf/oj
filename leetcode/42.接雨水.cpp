/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int cur_height = 0;
        int ans = 0;
        while(l<=r){
            if (height[l] > cur_height && height[r] > cur_height){
                cur_height++;
                continue;
            }
            if (height[l] <= cur_height){
                ans += cur_height-height[l];
                l++;
            }
            if (l<=r && height[r] <= cur_height){
                ans += cur_height-height[r];
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

