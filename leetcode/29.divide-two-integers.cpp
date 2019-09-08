/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Likes:    761
 * Dislikes: 3691
 * Total Accepted:    214.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

/* 考察位运算呀！！ */
/* 太多情况了吧 */
#include <cmath>
#include <limits>
#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0){
            return 0;
        }
        if (dividend == 0){
            return 0;
        }
        if (divisor == 1){
            return dividend;
        }
        if (divisor == INT_MIN && dividend != INT_MIN){
            return 0;
        }
        int dd = (dividend == INT_MIN)? INT_MAX : abs(dividend);
        int dd_sflag = (dividend == INT_MIN);
        int dr = (divisor == INT_MIN)? INT_MAX : abs(divisor);
        int same_flag = 0;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)){
            same_flag = 1;
        }
        int result = 0;
        for (int i = 31; i >= 0; i--){
            // cout << (dd>>i) << endl;
            if ((dd>>i) >= dr){
                result += 1<<i;
                dd -= dr<<i;
            }
        }
        if (dd_sflag && dd +1 == dr && result != INT_MAX){
            result ++;
        }
        if (same_flag == 0){
            return 0-result;
        }
        return result;
    }
};

// #include <cmath>
// #include <limits>

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         int same_flag = 0;
//         int sign_flag = dividend > 0? 1:0;

//         if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)){
//             same_flag = 1;
//         }
//         else{
//             same_flag = 0;
//         }
//         if (divisor == 1){
//             return dividend;
//         }
//         if (divisor == -1){
//             if (dividend <= INT_MIN && divisor == -1){
//                 return INT_MAX;
//             }
//             return -dividend;
//         }
//         int result = 0;
//         if (same_flag == 1 && sign_flag == 1){
//             // 同号相减
//             while (dividend - divisor >= 0){
//                 result++;
//                 dividend -= divisor;
//             }
//         }
//         else if (same_flag == 1 && sign_flag == 0){
//             while (dividend - divisor <= 0){
//                 result++;
//                 dividend -= divisor;
//             }
//         }
//         else if (same_flag == 0 && sign_flag == 1){
//             // 异号相加
//             while (dividend + divisor >= 0){
//                 result--;
//                 dividend += divisor;
//             }
//         }
//         else{
//             while(dividend + divisor <= 0){
//                 result--;
//                 dividend += divisor;
//             }
//         }
//         return result;
//     }
// };

