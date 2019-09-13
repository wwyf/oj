/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.03%)
 * Likes:    2158
 * Dislikes: 700
 * Total Accepted:    269.2K
 * Total Submissions: 867.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int left_i = 0;
        for (int i = len-2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                left_i = i;
                break;
            }
        }
        int max_j = 0;
        int temp = INT_MAX;
        for (int i = left_i+1; i < len; i++){
            if (nums[i] > nums[left_i] && nums[i] < temp){
                temp = nums[i];
                max_j = i;
            }
        }
        if (max_j == 0){
            return reverse(nums.begin(), nums.end());
        }
        swap(nums[left_i], nums[max_j]);
        sort(nums.begin() + left_i + 1, nums.end());
        return ;
        
    }
};

