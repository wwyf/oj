/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int res = 0;
        stack<int> mystack;
        mystack.push(0);
        int len = A.size();
        for (int i = 1; i < len; i++) {//生成单调栈
            if (A[mystack.top()] > A[i]) mystack.push(i);
        }
        for (int i = len - 1; i >= 0; i--) {//利用单调栈计算
            if (!mystack.empty()) {
            if (A[i] >= A[mystack.top()]) {
                res = max(res, i - mystack.top());
            mystack.pop();
            i++;//继续让他比较
            }
        }
            else break;
        }
        return res;
    }
};
// @lc code=end

