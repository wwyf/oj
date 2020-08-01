/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len < 2){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> & l, const vector<int> & r){
            if (l[1] == r[1]) return l[0] < r[0];
            return l[1] < r[1];
        });
        int cur_end = intervals[0][1];
        int i = 1;
        int count = 1;
        while (i < len) {
            if (intervals[i][0] >= cur_end){
                cur_end = intervals[i][1];
                count ++;
            } 
            i++;
        }

        return len-count;

    }
};
// @lc code=end

