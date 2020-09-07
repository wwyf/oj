/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

/*
2020-9-7 09:29:58
start

2020-9-7 09:33:48

2020-9-7 09:35:01

```
Accepted

156/156 cases passed (52 ms)

Your runtime beats 97.16 % of cpp submissions

Your memory usage beats 76.38 % of cpp submissions (26.2 MB)
```

*/

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if (A.empty()){
            return A;
        }
        int cur = K;
        int i = A.size()-1;
        while(i >= 0 && cur){
            cur = cur + A[i];
            A[i] = cur % 10;
            cur = cur / 10;
            i--;
        }
        while(cur){
            A.insert(A.begin(), cur % 10);
            cur = cur/10;
        }
        return A;
    }
};
// @lc code=end

