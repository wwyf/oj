/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int ans_first = left_bound(nums, target);
        int ans_last = right_bound(nums, target);
        return vector<int>{ans_first, ans_last};
    }
    int left_bound(vector<int> & nums, int target) {
        int left = 0, right = nums.size();;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] == target) {
                // 别返回，锁定左侧边界
                right = mid;
            }
        }
        // 最后要检查 left 越界的情况
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(vector<int> & nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] == target) {
                // 别返回，锁定右侧边界
                left = mid + 1;
            }
        }
        // 最后要检查 right 越界的情况，另外注意right需要减1
        if (right-1 < 0 || nums[right-1] != target)
            return -1;
        return right-1;
    }
};
// @lc code=end

