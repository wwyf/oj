/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int l = 1;
        int r = len;
        int mid = 0;
        int ans = 0;

        while(l < r){
            mid = l + (r-l)/2;

            // get cnt[mid]
            int cnt = 0;
            for (int i = 0; i < len; i++){
                if (nums[i] <= mid){
                    cnt++;
                }
            }

            if (cnt > mid){
                r = mid;
                ans = mid;
            } else if (cnt <= mid ){
                l = mid+1;
            }
            
        }

        // 寻找到第一个cnt[i] > i的位置

        return ans;

    }
};
// @lc code=end

