/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int> & l, const vector<int> & r){
            if (l[1] == r[1]) return l[0] < r[0];
            return l[1] < r[1];
        });
        // long cur_end = LONG_MIN;
        int cur_end = points[0][1];
        int ans = 1;
        for (int i = 1; i < points.size(); i++){
            if (points[i][0] > cur_end){
                cur_end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

