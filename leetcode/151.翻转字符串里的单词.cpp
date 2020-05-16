/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stack<string> rs;
        string curWord = "";
        for (auto c : s){
            if (c == ' '){
                if (!curWord.empty()){
                    rs.push(curWord);
                    curWord = "";
                } else {
                    continue;
                }
            } else {
                curWord += c;
            }
        }
        if (!curWord.empty()){
            rs.push(curWord);
        }
        string ans;
        if (rs.size() == 0){
            return "";
        } else {
            ans += rs.top();
            rs.pop();
            while(!rs.empty()){
                ans += " "+rs.top();
                rs.pop();
            }
            return ans;
        }
    }
};
// @lc code=end

