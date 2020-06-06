/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

/*

非常简单

Accepted
82/82 cases passed (16 ms)
Your runtime beats 5.1 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.9 MB)

*/

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ans = A;
        int yLen = A.size();
        int xLen = A[0].size();
        for (int i = 0; i < yLen; i++){
            // 关于这个(xLen+1)/2，还是需要注意一下
            for (int j = 0; j < (xLen+1)/2; j++){
                int l = ans[i][j];
                int r = ans[i][xLen-1-j];
                ans[i][j] = 1-r;
                ans[i][xLen-1-j] = 1-l;
            }
        }
        return ans;
    }
};
// @lc code=end

