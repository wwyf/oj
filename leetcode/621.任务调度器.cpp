/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskmap[26] = {0};
        for (auto c : tasks){
            taskmap[c-'A']++;
        }
        int i = 0;
        int cur_task = 25;
        int ans = 0;
        sort(taskmap, taskmap+26);
        while (taskmap[25] > 0){
            i = 0;
            cur_task = 25;
            while(i <= n){
                if (cur_task >= 0 && taskmap[cur_task] > 0){
                    taskmap[cur_task]--;
                    cur_task--;
                } else if (taskmap[25] == 0){
                    break;
                }
                ans++;
                i++;
            }
            sort(taskmap, taskmap+26);
        }
        return ans;

    }
};
// @lc code=end

