/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1){
            return true;
        }
        int can_j = 0; // 维护最远可达索引值
        for (int i = 0; i < nums.size(); i++){
            if (i <= can_j){
                can_j = max(can_j, i+nums[i]);
            } else {
                return false;
            }
            if (can_j >= nums.size()-1){
                return true;
            }
        }
        return true;

    }
};
// @lc code=end

