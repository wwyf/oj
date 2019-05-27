#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.30%)
# Likes:    2155
# Dislikes: 3271
# Total Accepted:    691.2K
# Total Submissions: 2.7M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
# of this problem, assume that your function returns 0 when the reversed
# integer overflows.
# 
#
class Solution:
    def reverse(self, x: int) -> int:
        # deel with zero
        if x == 0:
            return x
        # positive or not
        isPositive = x/abs(x)
        x = abs(x)
        # 消除末尾的0
        while x % 10 == 0:
            x = x/10
        # 逆转
        x_r = int(0)
        while x:
            n = x % 10
            # deal with overflow
            # -2147483648 ~ 2147483647
            old_x_r = x_r
            x_r = x_r * 10 + n
            if (x_r > 2147483647 or old_x_r > x_r):
                return 0
            x = (x-n)/10
        return int(isPositive*x_r)

        

