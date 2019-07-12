/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    1187
 * Dislikes: 86
 * Total Accepted:    359.7K
 * Total Submissions: 785.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
/*
类似的
问题在于：我还是没有在想清楚这个算法的正确性之前就把代码写了，然后导致有bug
思考力的提升十分关键！

 */
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0;
        int min_abs = INT_MAX;
        for (int i = 0; i < len-2; i++){
            int front = i+1;
            int end = len-1;
            int this_target = target - nums[i];
            while (front < end){
                int distance = nums[front] + nums[end] - this_target ;
                int this_abs = abs(distance);
                if  (this_abs < min_abs){
                    min_abs = this_abs;
                    ans = nums[i] + nums[front] + nums[end];
                }
                if (distance > 0){
                    while (end-1 > front && nums[end-1] == nums[end]) end--;
                    end--;
                }
                else if (distance < 0){
                    while (front+1 < end && nums[front+1] == nums[front]) front++;
                    front++;
                }
                else{
                    return target;
                }
                
            }
            while (i+1 < len-2 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};

