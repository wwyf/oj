/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1){
            return intervals;
        }
        vector<vector<int> > ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> & l, const vector<int> & r){
            if (l[0] == r[0]) return l[1] > r[1];
            return l[0] < r[0];
        });
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        int i = 1;
        while (i < intervals.size()){
            if (cur_start < intervals[i][0]){
                if (cur_end >= intervals[i][0]){
                    cur_end = max(cur_end, intervals[i][1]);
                    //cur_start = min(cur_start, intervals[i][0]);
                } else {
                    // cur_end < intervals[i][1] && cur_end < intervals[i][0]
                    // add new interval
                    ans.push_back(vector<int>{cur_start, cur_end});
                    cur_start = intervals[i][0];
                    cur_end = intervals[i][1];
                }
            }
            i++;
        }
        ans.push_back(vector<int>{cur_start, cur_end});
        return ans;
    }
};
// @lc code=end

