/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

/*
    2020-11-07 23:30:26
    start
    2020-11-07 23:37:45
    over

```
Accepted
30/30 cases passed (20 ms)
Your runtime beats 15.41 % of cpp submissions
Your memory usage beats 18.12 % of cpp submissions (7.3 MB)
```

少用了一个to_string

```
Accepted
30/30 cases passed (16 ms)
Your runtime beats 17.86 % of cpp submissions
Your memory usage beats 18.21 % of cpp submissions (7.3 MB)
```

1. 纯打表 https://leetcode-cn.com/problems/count-and-say/solution/da-biao-ju-ran-4ms-by-ninjayahoo/
2. 正常做：https://leetcode-cn.com/problems/count-and-say/solution/38-wai-guan-shu-lie-shuang-zhi-zhen-by-yiluolion/

*/
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1";
        }
        string prev = countAndSay(n-1);
        return des(prev);

    }
    string des(string s){
        string ans;
        int i = 0;
        int len = s.size();
        while(i < len){
            int count = 1;
            int num = s[i]-'0';
            while(i+1 < len && s[i+1] == s[i]){
                count++;
                i++;
            }
            ans += to_string(count)+s[i];
            i++;
        }
        return ans;
    }
};
// @lc code=end

