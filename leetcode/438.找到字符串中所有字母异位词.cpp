/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pNums(26,0);
        for (auto c : p){
            pNums[c-'a']++;
        }

        int pLen = p.size();
        if (s.size() < pLen){
            return vector<int>{};
        }
        vector<int> subNums(26,0);
        // init
        for (int i = 0; i < pLen-1; i++){
            subNums[s[i]-'a']++;
        }

        vector<int> ans;
        for (int i = pLen-1; i < s.size(); i++){
            subNums[s[i]-'a']++;
            int isEqual = true;
            for (int i = 0; i < 26; i++){
                if (subNums[i] != pNums[i]){
                    isEqual = false;
                    break;
                }
            }
            if (isEqual){
                ans.push_back(i+1-pLen);
            }
            subNums[s[i+1-pLen]-'a']--;
        }
        return ans;
    }
};
// @lc code=end

