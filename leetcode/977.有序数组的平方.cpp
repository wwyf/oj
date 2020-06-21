/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

/*
将问题转成了：两个有序数组的合并
看起来我基本就是和标答的方法2一样的。

复杂度分析：就是遍历了一次整个数组。所以是O(N)

看了答案，看到这种方法，机智啊！
优化：双指针改进：从两头向中间，免去寻找中间正负拐点

*/

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        if (len <= 0){
            return vector<int>{};
        }
        if (len == 1){
            return vector<int>{A[0]*A[0]};
        }
        int mid = 0; // 第一个大于等于0的数的索引
        // locate pointer
        while (mid < len && A[mid]<0){
            mid++;
        }
        // mid == 0 / mid = len / 0 < mid < len
        int r = mid-1;
        int l = mid;
        vector<int> ans;
        while (r != -1 && l != len){
            int r2 = A[r]*A[r];
            int l2 = A[l]*A[l];
            if (r2 < l2){
                ans.push_back(r2);
                r--;
            } else {
                ans.push_back(l2);
                l++;
            }
        }
        while (r!= -1){
            ans.push_back(A[r]*A[r]);
            r--;
        }
        while (l != len){
            ans.push_back(A[l]*A[l]);
            l++;
        }
        return ans;
    }
};
// @lc code=end

