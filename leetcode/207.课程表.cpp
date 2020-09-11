/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int> > g;
    vector<int> visit; // 0(not), 1(ing), 2(ok)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int> >(numCourses, vector<int>());
        for (auto p : prerequisites){
            g[p[1]].push_back(p[0]);
        }
        visit = vector<int>(numCourses, 0);
        for (int i = 0; i < numCourses; i++){
            if (visit[i] == 0){
                auto result = dfs(i);
                if (!result){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int n){
        if (visit[n] == 2){
            return true;
        }
        if (visit[n] == 1){
            return false;
        }
        visit[n] = 1;
        for (auto child : g[n]){
            if (visit[child] == 0){
                auto result = dfs(child);
                if (!result){
                    return result;
                }
            } else if (visit[child] == 1){
                return false;
            } else if (visit[child] == 2){
                continue;
            }
        }
        visit[n] = 2;
        return true;
    }
};
// @lc code=end

