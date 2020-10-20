/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <string>
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int ans = 0;

        for (int i = 0; i < len; i++){
            ans++;
            int l = i-1;
            int r = i+1;
            while(0 <= l  && r < len && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        for (int i = 0; i < len-1; i++){
            if (s[i] == s[i+1]){
                ans++;
                int l = i-1;
                int r = i+2;
                while(0 <= l  && r < len && s[l] == s[r]){
                    ans++;
                    l--;
                    r++;
                }

            }
        }

        return ans;

    }
};
// @lc code=end

