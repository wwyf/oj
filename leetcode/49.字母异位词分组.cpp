/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // str -> index
        int count = 0;
        unordered_map<string, int> str2index;
        for (auto s : strs){
            int num_of_chars[26] = {0};
            for (auto c : s){
                num_of_chars[c-'a']++;
            }
            string temp_s = "";
            for (auto n : num_of_chars){
                temp_s += "#"+to_string(n);
            }
            int cur_index;
            if (str2index.find(temp_s) == str2index.end()){
                cur_index = ans.size();
                str2index[temp_s] = ans.size();
                ans.push_back(vector<string>{});
            }else{
                cur_index = str2index[temp_s];
            }
            ans[cur_index].push_back(s);
        }
        return ans;
    }
};
// @lc code=end

