/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */


/*
2020-6-1 06:59:56
图，寻找入度为N-1，出度为0的点。
1. 遍历图节点，计算每个节点的入读和出度，并且寻找满足条件的节点。
暴力遍历的话，O(n^2)

2020-6-1 07:11:06
```
Accepted
92/92 cases passed (548 ms)
Your runtime beats 5.68 % of cpp submissions
Your memory usage beats 16.67 % of cpp submissions (70 MB)
```

看了看，大家方法都差不多，不过我就是加了一个set，我觉得应该能更快一些吧。我试试看不加set会怎样？

```
Accepted
92/92 cases passed (472 ms)
Your runtime beats 13 % of cpp submissions
Your memory usage beats 16.67 % of cpp submissions (69.1 MB)
```
看来不用set会更快一些。
2020-6-1 07:15:13 结束


*/
#include <vector>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 0){
            return -1;
        }
        if (N == 1){
            return 1;
        }
        int inDegree[1001] = {0};
        int outDegree[1001] = {0};
        for (auto ds : trust){
            outDegree[ds[0]] ++;
            inDegree[ds[1]] ++;
        }
        for (int p = 0; p <= N; p++){
            if (outDegree[p] == 0 && inDegree[p] == N-1){
                return p;
            }
        }
        return -1;

    }
    int findJudge2(int N, vector<vector<int>>& trust) {
        if (N == 0){
            return -1;
        }
        if (N == 1){
            return 1;
        }
        int inDegree[1001] = {0};
        int outDegree[1001] = {0};
        set<int> trustedPeople;
        for (auto ds : trust){
            outDegree[ds[0]] ++;
            inDegree[ds[1]] ++;
            trustedPeople.insert(ds[1]);
        }
        for (auto p : trustedPeople){
            if (outDegree[p] == 0 && inDegree[p] == N-1){
                return p;
            }
        }
        return -1;

    }
};
// @lc code=end

