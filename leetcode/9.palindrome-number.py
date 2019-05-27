#
# @lc app=leetcode id=9 lang=python3
#
# [9] Palindrome Number
#
# https://leetcode.com/problems/palindrome-number/description/
#
# algorithms
# Easy (43.29%)
# Likes:    1406
# Dislikes: 1293
# Total Accepted:    579.7K
# Total Submissions: 1.3M
# Testcase Example:  '121'
#
# Determine whether an integer is a palindrome. An integer is a palindrome when
# it reads the same backward as forward.
# 
# Example 1:
# 
# 
# Input: 121
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: -121
# Output: false
# Explanation: From left to right, it reads -121. From right to left, it
# becomes 121-. Therefore it is not a palindrome.
# 
# 
# Example 3:
# 
# 
# Input: 10
# Output: false
# Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
# 
# 
# Follow up:
# 
# Coud you solve it without converting the integer to a string?
# 
#
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # 以下这种做法在中间出现0的时候会gg
        # 不，并不会gg，是我写错了
        # 思路是：取头尾，相同就继续，不同就返回false
        # 有一个比较关键的是，奇数位如何处理的问题，我没有预想到的一点是，这个程序可以天然解决奇数位的问题
        # 反思：还是要想清楚程序的运行
        # negative is not a palindrome
        if x < 0:
            return False
        if x < 10:
            return True
        # find the biggest 10^n that can devide the number
        ten_pow = 10
        while ten_pow * 10 < x:
            ten_pow = ten_pow * 10       
        
        # judge
        while x != 0:
            front_num = x//ten_pow
            end_num = x%10
            if front_num != end_num:
                return False
            x = (x % ten_pow)//10
            # 漏了这一句！！
            ten_pow /= 100
        return True

        # 换一种思路：先判断位数，然后使用数组栈的方式来判断, ok的
        # # negative is not a palindrome
        # if x < 0:
        #     return False
        # if x < 10:
        #     return True
        # # find the biggest 10^n that can devide the number
        # len_num = 1
        # ten_pow = 10
        # while ten_pow <= x:
        #     ten_pow = ten_pow * 10       
        #     len_num = len_num + 1
        
        # # len_num is the length of number
        # isOdd = len_num % 2
        # halfIndex = len_num//2 - 1
        # i = 0
        # num_lists = []
        # while i <= halfIndex:
        #     num_lists.append(x % 10)
        #     x = x // 10
        #     i = i + 1
        # if isOdd:
        #     x = x // 10
        # while x != 0:
        #     current_num = x % 10
        #     last_num = num_lists.pop()
        #     if (current_num != last_num):
        #         return False
        #     x = x // 10
        # return True

        # 答案：原来和我原来的思路一样！！！
        # 我想错了，一些错误的想法让我以为那个思路是错的
        # ranger


