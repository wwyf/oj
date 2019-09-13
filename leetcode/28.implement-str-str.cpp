/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.86%)
 * Likes:    1031
 * Dislikes: 1486
 * Total Accepted:    488.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        if (nlen == 0){
            return 0;
        }
        if (hlen == 0 ){
            return -1;
        }
        if (nlen > hlen){
            return -1;
        }
        for (int i = 0; i <= hlen-nlen; i++ ){
            bool ok = true;
            for (int j = 0; j < nlen; j++ ){
                if (haystack[i+j] != needle[j]){
                    ok = false;
                    break;
                }
            }
            if (ok){
                return i;
            }
        }
        return -1;        
    }
};

