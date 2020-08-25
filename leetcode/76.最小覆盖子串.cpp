/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int tmap[256] = {0};
        int smap[256] = {0};
        int total_count = 0;
        for (int i = 0; i < t.size(); i++){
            if (tmap[t[i]] == 0) total_count++;
            tmap[t[i]]++;
        }
        int l = 0, r = 0;
        int ans = INT_MAX;
        int ans_l = 0;
        int ans_r = 0;
        int count = 0;
        while(l <= r && r < s.size()){
            while(r < s.size() && count < total_count){
                if (smap[s[r]]+1 == tmap[s[r]]) count++;
                smap[s[r]]++;
                r++;
            }
            while(l <= r && count == total_count){
                if (smap[s[l]] == tmap[s[l]]) count--;
                if (r-l < ans){
                    ans = r-l;
                    ans_l = l;
                    ans_r = r;
                }
                smap[s[l]]--;
                l++;
            }
        }
        return s.substr(ans_l, (ans_r-ans_l));
    }
};
// @lc code=end


int main(){
    cout << Solution{}.minWindow("ADOBECODEBANC", "ABCDEF") << endl;
}