/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    1082
 * Dislikes: 3354
 * Total Accepted:    332.1K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution {
// 还有另一种方法是一行一行算最后
// 这里是直接访问各个行的元素
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len == 0){
            return "";
        }
        // 没有处理这一种情况
        if (numRows == 1){
            return s;
        }
        int unit = 2*(numRows-1);
        int i = 0;
        string ans;
        while (i < len){
            ans += s[i];
            i += unit;
        }
        for (int k = 1; k <= numRows-2; k++){
            i = 0;
            while (i < len){
                if (i+k < len){
                    ans += s[i+k];
                }
                if (i+unit-k < len){
                    ans += s[i+unit-k];
                }
                i += unit;
            }
        }
        i = 0;
        while (i+numRows-1 < len){
            ans += s[i+numRows-1];
            i += unit;
        }
        return ans;
    }
};

