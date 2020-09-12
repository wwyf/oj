/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        return decodeString(1, s);

    }
    string decodeString(int n, string s){
        string ans;
        int i = 0;
        while(i < s.size()){
            // cout << s << endl;
            // cout << i << endl;
            if (isalpha(s[i])){
                ans.push_back(s[i]);
                i++;
                continue;
            } else if (isdigit(s[i])){
                int dn = s[i]-'0';
                int start_index = i+2;
                i = i+2;
                // find next paired "]"
                int count = 1;
                while(count!=0){
                    if (s[i] == '['){
                        count++;
                    }else if (s[i] == ']'){
                        count--;
                    }
                    i++;
                }
                int end_index = i-2;
                string cur = decodeString(dn, s.substr(start_index, (end_index-start_index+1)));
                ans += cur;
            }
            
        }
        string a;
        for (int i = 0; i < n; i++){
            a += ans;
        }
        return a;
    }
};
// @lc code=end

int main(){
    cout << Solution{}.decodeString("3[a]2[bc]") << endl;
}
