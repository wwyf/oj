/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */


/*
2020-8-10 09:33:21
1. 暴力 n^3

2. 用累加和实现n^2
2020-8-10 09:41:33
写好了

```
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++){
            sums[i+1] = sums[i] + nums[i];
        }
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j <= nums.size(); j++){
                int s = sums[j]-sums[i];
                if (s > max_sum){
                    max_sum = s;
                }

            }
        }
        return max_sum; 
    }
};
// @lc code=end

```

```
Accepted

202/202 cases passed (1428 ms)

Your runtime beats 5 % of cpp submissions

Your memory usage beats 19.18 % of cpp submissions (7.2 MB)
```

3. 实现O(n)
2020-8-10 09:46:30
想到本质上是在累加和数组中寻找i<j且sums[j]-sums[i]最大的i,j
维护一个当前最小值

2020-8-10 09:51:57
不科学啊，怎么更慢了
```
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++){
            sums[i+1] = sums[i] + nums[i];
        }
        int cur_min = INT_MAX;
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            if (sums[i] < cur_min){
                cur_min = sums[i];
            } else {
                int s = sums[i] - cur_min;
                if (s > max_sum){
                    max_sum = s;
                }
            }
        }
        return max_sum; 
    }
};
// @lc code=end


```


```
Accepted

202/202 cases passed (1564 ms)

Your runtime beats 5 % of cpp submissions

Your memory usage beats 7.97 % of cpp submissions (7.3 MB)
```

*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            dp = max(nums[i], dp+nums[i]);
            max_sum = max(max_sum, dp);
        }
        return max_sum;
    }
};
// @lc code=end

