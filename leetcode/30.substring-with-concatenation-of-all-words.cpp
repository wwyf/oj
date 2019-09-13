/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.10%)
 * Likes:    618
 * Dislikes: 994
 * Total Accepted:    145.3K
 * Total Submissions: 602.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
学习 unordered_map 数据结构
其实map也ok
另外，unordered_map 比 map 更快
https://stackoverflow.com/questions/2196995/is-there-any-advantage-of-using-map-over-unordered-map-in-case-of-trivial-keys
```
$ ./time_hash_map
TR1 UNORDERED_MAP (4 byte objects, 10000000 iterations):
map_grow              126.1 ns  (27427396 hashes, 40000000 copies)  290.9 MB
map_predict/grow       67.4 ns  (10000000 hashes, 40000000 copies)  232.8 MB
map_replace            22.3 ns  (37427396 hashes, 40000000 copies)
map_fetch              16.3 ns  (37427396 hashes, 40000000 copies)
map_fetch_empty         9.8 ns  (10000000 hashes,        0 copies)
map_remove             49.1 ns  (37427396 hashes, 40000000 copies)
map_toggle             86.1 ns  (20000000 hashes, 40000000 copies)

STANDARD MAP (4 byte objects, 10000000 iterations):
map_grow              225.3 ns  (       0 hashes, 20000000 copies)  462.4 MB
map_predict/grow      225.1 ns  (       0 hashes, 20000000 copies)  462.6 MB
map_replace           151.2 ns  (       0 hashes, 20000000 copies)
map_fetch             156.0 ns  (       0 hashes, 20000000 copies)
map_fetch_empty         1.4 ns  (       0 hashes,        0 copies)
map_remove            141.0 ns  (       0 hashes, 20000000 copies)
map_toggle             67.3 ns  (       0 hashes, 20000000 copies)
```
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()){
            return ans;
        }
        int words_num = words.size();
        int wordlen = words[0].size();
        int slen = s.size();
        int alllen = wordlen * words_num;
        if (words_num == 0 || slen < alllen){
            return ans;
        }
        unordered_map<string, int> counts, records;
        for (int i = 0; i < words_num; i++){
            counts[words[i]]++;
        }
        // 重要：这里只需要wordlen就好了
        for (int i = 0; i < wordlen; i++){
            // 从i开始搜索
            int left = i;
            int sum = 0;
            records.clear();
            // 缺等号
            for (int j = i; j <= slen - wordlen; j+=wordlen){
                // 测试j开头的word是否在words中，并根据条件判断此时是否需要扩大窗口。
                string cur = s.substr(j, wordlen);
                if (counts.count(cur)){
                    // cur这个word在单词表里面
                    records[cur]++;
                    sum++;
                    while (records[cur] > counts[cur]){
                        records[s.substr(left, wordlen)]--;
                        sum--;
                        left += wordlen;
                    }
                    if (sum == words_num){
                        ans.push_back(left);
                    }
                }
                else{
                    records.clear();
                    sum = 0;
                    left = j + wordlen;
                }
            }
        }
        return ans;

    }
};
