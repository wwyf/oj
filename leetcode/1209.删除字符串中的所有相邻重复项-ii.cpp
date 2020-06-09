/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 * 
 */
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int haveRemoved = false;
        int i=0,j=0;
        // 这个循环条件出了很多bug
        while (s.size() >= k && i <= s.size()-k){
            // cout << s << endl;
            char c = s[i];
            int count = 1;
            for (int j = 1; j < k; j++){
                if (s[i+j] != c){
                    break;
                }
                count++;
            }
            if (count == k){
                // 找到了连续的k个相同的字母
                // cout << s << endl;
                s.erase(i, k);
                // cout << s << endl;
                haveRemoved = true;
            } else {
                // 如果找不到连续的k个相同，就向前移动光标，移动count个单位。
                i+=count;
            }
        }
        if (haveRemoved){
            // cout << s << endl;
            return removeDuplicates(s, k);
        } else {
            return s;
        }

    }
};
// @lc code=end


int main(){
    cout << Solution{}.removeDuplicates("deeedbbcccbdaa", 3) << endl;
    cout << Solution{}.removeDuplicates("ybthyyyy", 4) << endl;
}