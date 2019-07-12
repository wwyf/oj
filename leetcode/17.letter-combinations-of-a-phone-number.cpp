/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.52%)
 * Likes:    2303
 * Dislikes: 310
 * Total Accepted:    409.9K
 * Total Submissions: 973.5K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
// 有点简单？？
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapper[10];
        mapper[2] = {"a","b","c"};
        mapper[3] = {"d","e","f"};
        mapper[4] = {"g","h","i"};
        mapper[5] = {"j","k","l"};
        mapper[6] = {"m","n","o"};
        mapper[7] = {"p","q","r","s"};
        mapper[8] = {"t","u","v"};
        mapper[9] = {"w","x","y","z"};
        int len = digits.size();
        vector<string> ans;
        for (int i = 0; i < len; i++){
            ans = getCombination(ans, mapper[digits[i]-'0']);
        }
        return ans;
    }

    vector<string> getCombination(const vector<string> & v1, const vector<string> & v2){
        int len1 = v1.size();
        int len2 = v2.size();
        if (len1 == 0){
            return v2;
        }
        if (len2 == 0){
            return v1;
        }
        vector<string> ans;
        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                ans.push_back(v1[i]+v2[j]);
            }
        }
        return ans;
    }
};

