#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (44.16%)
# Likes:    10765
# Dislikes: 359
# Total Accepted:    1.8M
# Total Submissions: 4.1M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
# 
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
# 
# Example:
# 
# 
# Given nums = [2, 7, 11, 15], target = 9,
# 
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
# 
# 
# 
# 
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # # so violence
        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             return [i,j]

        # from google solution
        map = {}
        for i in range(len(nums)):
            if nums[i] not in map:
                # 记录：如果之后遇到了target - nums[i] 这个数，那就能够直接找到
                map[target - nums[i]] = i
            else:
                return map[nums[i]], i
        return -1,-1
        

