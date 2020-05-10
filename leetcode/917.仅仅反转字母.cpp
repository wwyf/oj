/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

/*

太简单了
拿一个栈存放就好。
方法：
1. 栈
2. 双指针
*/


// @lc code=start
#include <cctype>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char> rc;
        for (auto c : S){
            if (isalpha(c)){
                rc.push(c);
            }
        }
        for (auto & c : S){
            if (isalpha(c)){
                c = rc.top();
                rc.pop();
            }
        }
        return S;
    }
};
// @lc code=end

