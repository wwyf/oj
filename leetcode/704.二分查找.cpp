/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
/*
2020-8-17 10:02:41

2020-8-17 10:05:34
搞定
*/

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int li = 0;
        int ri = nums.size();
        int mid = 0;
        while(li < ri){
            mid = li+(ri-li)/2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] > target){
                ri = mid;
            } else {
                li = mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

