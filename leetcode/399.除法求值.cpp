/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<string, pair<string, double>> m;
    unordered_set<string> existed;
    pair<string ,double> find_root_value(const string & s, double v){
        if (m.find(s) == m.end()){
            return pair(s,v);
        }
        v *= m[s].second;
        return find_root_value(m[s].first, v);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        if (len == 0){
            return vector<double>{};
        }
        for (int i = 0; i < len; i++){
            existed.insert(equations[i][0]);
            existed.insert(equations[i][1]);
            auto root1 = find_root_value(equations[i][0], 1);
            auto root2 = find_root_value(equations[i][1], 1);
            if (root1.first != root2.first){
                double new_value = values[i]*root2.second/root1.second;
                m[root1.first] = pair<string, double>(root2.first, new_value);
            }
        }
        len = queries.size();
        vector<double> ans(len, 0);
        for (int i = 0; i < len; i++){
            if(existed.find(queries[i][0]) == existed.end() || existed.find(queries[i][1]) == existed.end()){
                ans[i] = -1;
                continue;
            }
            auto root1 = find_root_value(queries[i][0], 1);
            auto root2 = find_root_value(queries[i][1], 1);
            if (root1.first != root2.first){
                ans[i] = -1;
            } else {
                ans[i] = root1.second/root2.second;
            }
        }
        return ans;
    }
};
// @lc code=end

