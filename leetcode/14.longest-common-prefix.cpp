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

// 性能需要提升
// https://leetcode.com/problems/longest-common-prefix/solution/

class Solution {
public:
    string longestCommonPrefix3(vector<string>& strs) {
        // 递归解决
        // 将大问题拆分成小问题
        // 最快！！
        if (strs.empty()){
            return "";
        }
        return longestCommonPrefix(strs, 0, strs.size());
    }
    string longestCommonPrefix(vector<string> & strs, int l, int r){
        // r-l 实际个数
        if (r-l == 1){
            return strs[l];
        }
        int mid = (l+r)/2;
        // [l .... mid)  [mid ... r)
        string l_str = longestCommonPrefix(strs, l, mid);
        string r_str = longestCommonPrefix(strs, mid, r);
        return commonPrefix(l_str, r_str);
    }
    string commonPrefix(const string & l, const string & r){
        // 返回公共前缀
        int min_common_len = min(l.size(), r.size());
        int ans = 0;
        for (int i = 0; i < min_common_len; i++){
            if (l[i] == r[i]){
                ans++;
            }
            else{
                break;
            }
        }
        return l.substr(0,ans);
    }
    string longestCommonPrefix2(vector<string>& strs) {
        // from solution
        // 优点在于：实际上只需要几个字符串，就可以将搜索的复杂度控制在O(N)的常数倍。
        // 理论的复杂度为O(S)，s为字符个数
        // important!
        if (strs.empty()){
            return "";
        }
        string common_str = strs[0];
        for (auto s : strs){
            string ans = "";
            int len_common_str = common_str.size();
            int len_s = s.size();
            for (int i = 0; i < min(len_common_str, len_s); i++){
                if (s[i] == common_str[i]){
                    ans += s[i];
                }
                else{
                    break;
                }
            }
            common_str = ans;
        }
        return common_str;
    }
    string longestCommonPrefix1(vector<string>& strs) {
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

