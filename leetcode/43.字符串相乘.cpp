/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 * 
 */
/*
```

https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
https://leetcode-cn.com/problems/multiply-strings/solution/gao-pin-mian-shi-xi-lie-zi-fu-chuan-cheng-fa-by-la/

Accepted

311/311 cases passed (4 ms)

Your runtime beats 99.07 % of cpp submissions

Your memory usage beats 59.09 % of cpp submissions (6.9 MB)
```
*/

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = num1.size()-1; i >= 0; i--){
            for (int j = num2.size()-1; j >= 0; j--){
        // 顺序不能倒过来！！！
        // for (int i = 0; i < num1.size(); i++){
        //     for (int j = 0; j < num2.size(); j++){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                // i+j, i+j+1
                mul += ans[i+j+1];
                ans[i+j+1] = mul%10;
                ans[i+j] += mul/10;  // BUG!
            }
        }
        int start_index = 0;
        while((start_index < ans.size()) && ans[start_index] == 0){
            start_index++;
        }
        if (start_index == ans.size()){
            return "0";
        }else {
            string s;
            for (int i = start_index; i < ans.size(); i++){
                s.push_back(ans[i]+'0');
            }
            return s;
        }
    }
};
// @lc code=end

