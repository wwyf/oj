/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int>> tempGroup;
        int len = groupSizes.size();
        for (int i = 0; i < len ; i++){
            int s = groupSizes[i];
            tempGroup[s].push_back(i);
            if (tempGroup[s].size() == s){
                ans.push_back(tempGroup[s]);
                tempGroup[s].clear();
            }
        }
        return ans;
    }
};
// @lc code=end

