/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */
/*
Accepted
200/200 cases passed (112 ms)
Your runtime beats 6.94 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6.2 MB)
用了__builtin_popcount函数之后
Accepted
200/200 cases passed (68 ms)
Your runtime beats 16.33 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6.2 MB)

学习题解：
https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/solution/ti-jiao-ji-lu-zhong-0msti-jiao-de-dai-ma-han-yi-by/
收获：
```
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res=0;
        for(int i=L;i<=R;i++)
        res+=(665772>>__builtin_popcount(i))&1 ;
        return res;
    }
};

作者：bowen-17
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/solution/ti-jiao-ji-lu-zhong-0msti-jiao-de-dai-ma-han-yi-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
1. __builtin_popcount函数的使用，用来求一个无符号整数中1的个数。
2. 将质数编码到665772中，例子，如果i中有5个1，则右移5位，此时655722右移5位之后最低位的值就代表了5是否是质数。

学习题解2：
https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/solution/javachao-yue-99de-jian-dan-xie-fa-by-flychenkai/
同样的，不需要map，直接用这样的数组就可以记录查询结果。
```java
class Solution {
   public int countPrimeSetBits(int L, int R) {
        //0-20的质数列表，prime[i]为1，则i为质数
        int[] primes = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
        int res = 0;
        for (int i = L; i <= R; i++) {
            int t = Integer.bitCount(i);
            res += primes[t];
        }
        return res;
    }
}

作者：FlyChenKai
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/solution/javachao-yue-99de-jian-dan-xie-fa-by-flychenkai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

*/
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    map<int, int> isPrime;
    int countPrimeSetBits(int L, int R) {
        int PrimeNumbers[11] = {2,3,5,7,11,13,17,19,23,29,31};
        for (int i = 0; i < 11; i++){
            isPrime[PrimeNumbers[i]] = 1;
        }
        int c = 0;
        int ans = 0;
        for (int i = L; i <= R; i++){
        //    c = countOne(i);
           c = __builtin_popcount(i);
           if (isPrime[c] == 1){
               ans++;
           } 
        }
        return ans;

    }
    int countOne(int n){
        if (n == 0 ){
            return 0;
        }
        int ans = 1;
        int r = 0;
        while(n != 1){
            r = n % 2;
            n = n / 2;
            if (r == 1){
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

