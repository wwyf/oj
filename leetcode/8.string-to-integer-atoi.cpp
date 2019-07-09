/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.64%)
 * Likes:    990
 * Dislikes: 6252
 * Total Accepted:    382.7K
 * Total Submissions: 2.6M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */

// NOTE: 学到了如何 detect overflow https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-multiply-overflow 

// 这道题主要难点在于：如何预判溢出，中间有几个WA都是因为溢出逻辑不正确导致的，如边界条件，等号没有写
// 然后另一个就是，没有理解好题意。
// 不过的确，有点无聊，一道考if else 的题

#include <limits.h>

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int num = 0;
        int cp = 0;
        int s_flag = 1;
        int over_flag = 0;
        int num_flag = 0;
        // flag
        while (str[cp] == ' '){
            cp++;
        }
        // now str[cp] != 0
        if (str[cp] == '+'){
            s_flag = 1;
            cp++;
        }
        else if (str[cp] == '-'){
            s_flag = -1;
            cp++;
        }
        while (cp < len && '0' <= str[cp] && str[cp] <= '9'){
            if (num_flag == 0){
                num_flag = 1;
            }
            if (over_flag){
                cp++;
                continue;
            }
            //  num = num*10 + s_flag * (str[cp]-'0');
            // detect overflow num*10
            if (s_flag*num <= INT_MAX/10){
                num = num*10;
            }
            else{
                over_flag = 1;
            }
            // detect overflow in +
            int single_num = s_flag * (str[cp]-'0');
            if (s_flag == 1){
                if (single_num <= INT_MAX - num){
                    num = num + single_num;
                }
                else{
                    over_flag = 1;
                }
            }
            else{
                if (single_num >= INT_MIN - num){
                    num = num + single_num;
                }
                else{
                    over_flag = 1;
                }                
            }
            cp++;
        }
        // if (cp < len && str[cp] != ' ' && str[cp] != '.'){
        //     num_flag = 0;
        // }

        if (!num_flag){
            return 0;
        }
        if (over_flag){
            if (s_flag == 1){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        return num;
    }
};
