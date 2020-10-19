/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> mystack;
        int len = T.size();
        vector<int> ans(len);
        for (int i = 0; i < len; i++){
            while(!mystack.empty() && T[mystack.top()] < T[i]){
                int prev_index = mystack.top();
                mystack.pop();
                ans[prev_index] = i - prev_index;
            }
            // mystack.empty() || mystack.top() >= T[i]
            mystack.push(i);
        }
        return ans;
    }
};
// @lc code=end

