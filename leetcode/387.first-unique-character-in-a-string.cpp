/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.63%)
 * Likes:    1178
 * Dislikes: 86
 * Total Accepted:    315.2K
 * Total Submissions: 622.5K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution1 {
public:
    int firstUniqChar(string s) {
        map<char, int> counts;
        int len = s.size();
        for (int i = 0; i < len; i++){
            counts[s[i]]++;
        }
        for (int i = 0; i < len; i++){
            if (counts[s[i]] == 1){
                return i;
            }
        }
        return -1;

    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        int counts[27];
        memset(counts, 0, 27*sizeof(int));
        int len = s.size();
        for (int i = 0; i < len; i++){
            counts[s[i]-'a']++;
        }
        for (int i = 0; i < len; i++){
            if (counts[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;

    }
};

