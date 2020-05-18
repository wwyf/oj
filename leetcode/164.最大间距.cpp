/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxDiff = 0;
        for (int i = 0; i < len-1; i++){
            int diff = nums[i+1]-nums[i];
            if (diff > maxDiff){
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
};
// @lc code=end

