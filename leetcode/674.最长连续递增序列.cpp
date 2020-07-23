/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

/*

Accepted

36/36 cases passed (16 ms)

Your runtime beats 96.53 % of cpp submissions

Your memory usage beats 6.67 % of cpp submissions (10.6 MB)
*/

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0){
            return 0;
        }
        int curAns = 1;
        int ans = 1;
        for (int i = 1; i < len; i++){
            if (nums[i] > nums[i-1]){
                curAns++;
                ans = max(ans, curAns);
            } else {
                curAns = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

