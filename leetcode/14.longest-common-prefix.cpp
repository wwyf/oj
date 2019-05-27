/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.50%)
 * Likes:    1351
 * Dislikes: 1299
 * Total Accepted:    464.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <string>
#include <vector>
using namespace std;

// TODO 性能需要提升

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // important!
        if (strs.size() == 0){
            return "";
        }
        string s = strs[0];
        int len_s = s.size();
        int offset = 0;
        int isCommon = 1;
        while (offset < len_s){
            isCommon = 1;
            char c = s[offset];
            for (auto i : strs){
                if (i[offset] != c){
                    isCommon = 0;
                    break;
                }
            }
            if (isCommon){
                offset++;
            }
            else{
                break;
            }
        }
        return s.substr(0,offset);
    }
};

