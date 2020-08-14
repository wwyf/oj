/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        if (l1 > l2) return false;

        int c1[26];
        int c2[26];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for (int i = 0; i < s1.size(); i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }

        int equal_count = 0;
        for (int i = 0; i < 26; i++){
            if (c1[i] == c2[i]){
                equal_count++;
            }
        }
        for (int i = s1.size(); i < s2.size(); i++){
            if (equal_count == 26){
                return true;
            }
            int r = s2[i]-'a';
            int l = s2[i-(s1.size())]-'a';
            // add a c to right
            c2[r]++;
            if (c2[r] == c1[r]){
                equal_count++;
            } else if (c2[r] == c1[r]+1) {
                equal_count--;
            }
            c2[l]--;
            if (c2[l] == c1[l]){
                equal_count++;
            } else if (c2[l] == c1[l]-1) {
                equal_count--;
            }
        }
        return equal_count == 26;
    }
};
// @lc code=end

int main(){
    cout << Solution{}.checkInclusion("abc", "bbbca") << endl;
}

