/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 *
 * [1353] 最多可以参加的会议数目
 */

#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    const int MAX = 100001;
    int maxEvents(vector<vector<int>>& events) {
        vector< vector<int> > startAt(MAX);
        int eventsLen = events.size();
        for (int i = 0; i < eventsLen; i++){
            startAt[events[i][0]].emplace_back(i); 
        }
        priority_queue<int, vector<int>, greater<>> pq;
        int ans = 0;
        for (int i = 1; i < MAX; i++){
            for (auto eIndex : startAt[i]){
                pq.push(events[eIndex][1]);
            }
            while (!pq.empty() && pq.top() < i){
                pq.pop();
            }
            if (!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

