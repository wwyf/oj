/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.36%)
 * Likes:    5529
 * Dislikes: 303
 * Total Accepted:    927.3K
 * Total Submissions: 3.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

class Solution1 {
// TLE版本
// the naive solution
public:
    int lengthOfLongestSubstring(string s) {
        // naive 遍历子串
        int LengthOfLongest = 0;
        int LengthOfString = s.size();
        for (int i = 0; i < LengthOfString; i++){
            for (int j = i; j < LengthOfString; j++){
                // s[i] - s[j]
                int hash[256]={0};
                int k = i;
                int thisLength = 0;
                // 求该子串的不重复前缀长度
                while (k <= j){
                    if (!hash[s[k]]){
                        // 没有遇见过这个数字
                        thisLength++;
                        hash[s[k]] = 1;
                        k++;
                    }
                    else{
                        break;
                    }
                }
                if (thisLength > LengthOfLongest){
                    LengthOfLongest = thisLength;
                }
            }
        }
        return LengthOfLongest;
    }
};

class Solution2 {
// 这个是遍历结尾，想了想，遍历开头也行，遍历子串是最蠢的。
public:
    int lengthOfLongestSubstring(string s) {
        // 只需要遍历每个位置，计算以该位置结尾的字符串中，不含重复字符的最长字符串即可。
        int LengthOfString = s.size();
        if (LengthOfString == 0){
            return 0;
        }
        int LengthOfResult = 1;
        int thisLength = 1;
        int left_index = 0;
        for (int i = 1; i < LengthOfString; i++){
            // 遍历结尾，计算以该结尾的最长子串长度
            // 新加一个字符 s[i] ，在子串 s[left_index] - s[i-1] 之间寻找是否有字符重合
            int hash[256] = {0};
            int j = i;
            hash[s[i]] = 1;
            while (j-1 >= left_index){
                if (!hash[s[j-1]]){
                    // 没见过
                    hash[s[j-1]] = 1;
                    j--;
                }
                else{
                    break;
                }
            }
            thisLength = i - j + 1;
            if (LengthOfResult < thisLength){
                LengthOfResult = thisLength;
            }
        }
        return LengthOfResult;
    }
};


class Solution3{
// 窗口滑动法
// 咦为什么这种更慢？？
public:
    int lengthOfLongestSubstring(string s) {
        int LengthOfResult = 0;
        int LengthOfString = s.size();
        if (LengthOfString == 0){
            return 0;
        }
        std::set<char> HashSet; 
        int l = 0,r = 0;
        while (l < LengthOfString && r < LengthOfString){
            // check s[r]
            auto is_in = HashSet.find(s[r]);
            if (is_in != HashSet.end()){
                // found
                // 注意这里erase的是s[l]
                HashSet.erase(s[l]);
                l++;
            }
            else{
                // not found
                HashSet.insert(s[r]);
                r++;
                LengthOfResult = std::max(LengthOfResult, r-l);
            }
        }
        return LengthOfResult;
    }
};

class Solution{
// 优化的窗口滑动法
public:
    int lengthOfLongestSubstring(string s) {
        int LengthOfResult = 0;
        int LengthOfString = s.size();
        if (LengthOfString == 0){
            return 0;
        }
        int HashSet[256];
        for (int i = 0; i < 256; i++){
            HashSet[i] = -1;
        }
        int l = 0,r = 0;
        while (l < LengthOfString && r < LengthOfString){
            // check s[r]
            int is_in = HashSet[s[r]];
            if (is_in != -1){
                // found
                int index = HashSet[s[l]];
                for (int i = l; i <= index; i++){
                    HashSet[s[i]] = -1;
                }
                l = index + 1;
            }
            else{
                // not found
                HashSet[s[r]] = r;
                r++;
                LengthOfResult = std::max(LengthOfResult, r-l);
            }
        }
        return LengthOfResult;
    }
};


