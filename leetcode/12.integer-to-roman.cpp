/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (50.90%)
 * Likes:    618
 * Dislikes: 1945
 * Total Accepted:    241.7K
 * Total Submissions: 470.2K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    char symbolTable[5] = {'I', 'X', 'C', 'M'};
    char fiveSymbolTable[5] = {'V', 'L', 'D'};
    string intToRoman(int num) {
        string ans;
        int n;
        int offset = 0;
        while (num){
            n = num % 10;
            ans = singleIntIoRoman(offset, n) + ans;
            offset++;
            num = num / 10;
        }
        return ans;
    }

    string singleIntIoRoman(int offset, int num){
        // offset from 0(right)(low) - 3(left)(high)
        string ans;
        if (num == 0){
            return ans;
        }
        else if (0 < num && num <= 3){
            return string(num, symbolTable[offset]);
        }
        else if (num == 4){
            return string(1, symbolTable[offset]) + string(1, fiveSymbolTable[offset]);
        }
        else if (num == 5){
            return string(1, fiveSymbolTable[offset]);
        }
        else if (6 <= num && num <= 8){
            return string(1, fiveSymbolTable[offset]) + string(num-5, symbolTable[offset]);
        }
        else if (9 == num){
            return string(1, symbolTable[offset]) + string(1, symbolTable[offset+1]);
        }
        return ans;
    }
};


/* 看讨论看到的一种很简便的解法（其实一样）
    string intToRoman(int num) {
        string romanPieces[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                              "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                              "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                              "","M","MM","MMM","MMMM"};
        return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20]
            +romanPieces[(num/10)%10+10]+romanPieces[num%10];
    }

 */

