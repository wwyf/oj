/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        // ans.reserve(A.size()+B.size());
        int ai = 0;
        int bi = 0;
        int Asize = A.size();
        int Bsize = B.size();
        while(ai < Asize && bi < Bsize){
            auto a = A[ai];
            auto b = B[bi];
            if (a[1] >= b[0] && b[1] >= a[0]){
                // have
                ans.push_back(vector<int>{max(a[0],b[0]), min(a[1],b[1])});
            }

            if (A[ai][1] < B[bi][1]){
                ai++;
            } else if (A[ai][1] > B[bi][1]) {
                bi++;
            } else {
                ai++;
                bi++;
            }
        }
        return ans;
    }
};
// @lc code=end

