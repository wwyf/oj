/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (54.73%)
 * Likes:    511
 * Dislikes: 847
 * Total Accepted:    251.2K
 * Total Submissions: 459K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */
class Solution1 {
public:
    int addDigits(int num) {
       while(num >= 10){
           int sum = 0;
           int temp = num;
           while (temp){
               sum += temp%10;
               temp /= 10;
           }
           num = sum;
       } 
       return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        return (num%9 == 0)? 9 : num%9;
    }
};

