/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, cur, target, 0);
        return ans;
    }
    void dfs(vector<int> & candidates, vector<int> & cur, int target, int l){
        for (int i = l; i < candidates.size() ; i++){
            int next_target = target-candidates[i];
            if (next_target < 0){
                continue;
            } else if (next_target == 0){
                cur.push_back(candidates[i]);
                ans.push_back(cur);
                cur.erase(cur.end()-1);
            } else {
                // try candidates[i]
                cur.push_back(candidates[i]);
                dfs(candidates, cur, next_target, i);
                cur.erase(cur.end()-1);
            }
        }
    }
};
// @lc code=end

