/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <string>
#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> ns;
        stack<string> ss;
        int pos = 0;
        while(pos < s.size()){
            if (isdigit(s[pos])){
                // push a num into stack ns
                int num = s[pos]-'0';
                while(isdigit(s[pos+1])){
                    num = num*10 + s[pos+1]-'0';
                    pos++;
                }
                ns.push(num);
            } else if (isalpha(s[pos])){
                ss.push(string(1, s[pos]));
            } else if (s[pos] == '['){
                ss.push(string(1, s[pos]));
            } else if (s[pos] == ']'){
                string cur_string;
                while(ss.top() != "["){
                    cur_string = ss.top() + cur_string;
                    ss.pop();
                }
                ss.pop();
                int num = ns.top();
                ns.pop();
                string final_string;
                for (int i = 0; i < num; i++) final_string += cur_string;
                ss.push(final_string);
            }
            pos++;
        }
        string ans;
        while(!ss.empty()){
            ans = ss.top() + ans;
            ss.pop();
        }
        return ans;
    }
};
// @lc code=end

int main(){
    cout << Solution{}.decodeString("3[a]2[bc]") << endl;
}
