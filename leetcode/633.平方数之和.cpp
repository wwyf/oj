/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

/*

1. 寻找一个最大的n，是n^2 <= c
2. 两层遍历，找到a^2 + b^2 = c

题意理解不清晰
1. 两个数的平方和？什么数？原来可以为0.
2. 0,1这两个算例如何理解呢？0^2 + 0^2 = 0
3. 2147482647 对这个算例而言，问题在于：在寻找最大的n时，可能发生n^2溢出的情况，如下：

```
Runtime Error
98/124 cases passed (N/A)
Error
Line 6: Char 21: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.cpp)
Line 6: Char 21: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:16:21
Testcase
2147482647
```

想到了一个更好的算法，就是：
1. 先计算所有小于n^2<= c的n列表，如果遇到n^2=c的就直接输出
2. 若不存在n^2 = c，则遍历列表n得到n_i
    1. 使用二分查找在n列表中寻找(c-(n_i^2))，如果找得到，返回true。
3. 如果遍历了列表之后仍然找不到，则返回false

时间复杂度：列表n的长度是sqrt(n),每个都需要二分查找，再乘上log(sqrt(n))，也就是logn了。所以就是sqrt(n)log(n)
空间复杂度：sqrt(n)

PS：循环的等号一定要多思考一下。

但是现在TLE了。

```
Time Limit Exceeded
26/124 cases passed (N/A)
Testcase
999999999
```

*/
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = int(sqrt(c));
        for (int i = 0; i <= a; i++){
            int l = c-i*i;
            double b = sqrt(l);
            if (b == int(b)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

#include <iostream>

int main(){
    cout << Solution{}.judgeSquareSum(999999999) << endl;
    // 真的很慢，为什么
    // 因为find不是二分！！！
}