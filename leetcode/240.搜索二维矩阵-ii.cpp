/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r_max = -1;
        int r_min = -1;
        // find thr first element in matrix[0][x] where matrix[0][x] > target
        int li,hi,mid;
        int m = matrix.size();
        if (m == 0){
            return false;
        }
        int n = matrix[0].size();
        if (n == 0){
            return false;
        }
        li = 0;
        hi = m;
        while(li < hi){
            mid = li + (hi-li)/2;
            if (matrix[mid][0] == target){
                return true;
            } else if (matrix[mid][0] < target){
                li = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (li <= 0){
            return false;
        }
        r_max = li-1;

        // find the first element in matrix[m-1][x] where matrix[m-1][x] > target
        li = 0;
        hi = m;
        while(li < hi){
            mid = li + (hi-li)/2;
            if (matrix[mid][n-1] == target){
                return true;
            } else if (matrix[mid][n-1] < target){
                li = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (li >= m){
            return false;
        }
        r_min = li;

        if (r_min > r_max){
            return false;
        }

        // find target between r_min and r_max
        for (int i = r_min; i <= r_max; i++){
            li = 0;
            hi = n;
            while(li < hi){
                mid = li + (hi-li)/2;
                if (matrix[i][mid] == target){
                    return true;
                } else if (matrix[i][mid] < target){
                    li = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }

        return false;
    }
};
// @lc code=end

