/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        int cur = 0;
        int temp;
        while(cur <= p2){
            if (nums[cur] == 0){
                swap(nums[cur], nums[p0]);
                p0++;
                cur++;
            } else if (nums[cur] == 1){
                cur++;
            } else if (nums[cur] == 2){
                swap(nums[cur], nums[p2]);
                p2--;
            }
        }
        return;
    }
};
// @lc code=end

