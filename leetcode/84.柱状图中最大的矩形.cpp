/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int heights_len = heights.size();
        int ans = 0;
        for (int i = 0; i < heights_len; i++){
            if (s.empty()){
                s.push(i);
                continue;
            }
            if (s.top() <= heights[i]){
                s.push(i);
            } else {
                while(!s.empty() && s.top() > heights[i]){
                    // s.top() > heights[i]
                    ans = max(ans, heights[s.top()] * (i-s.top()));
                    s.pop();
                }
                if (s.empty()){
                    ans = max(ans, heights[])
                }
            }

        }
        
    }
};
// @lc code=end

