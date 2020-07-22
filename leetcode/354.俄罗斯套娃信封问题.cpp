/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
// A hash function used to hash a pair of any kind 
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort
        int len = envelopes.size();
        if (len <= 1) return len;
        // w升序排列，w相同的话h降序排列
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&l, vector<int>&r){
            if (l[0] == r[0]) return l[1]>r[1];
            return l[0]<r[0];
        });
        // 在h数组中确定最长上升子序列的长度
        vector<int> tail(len, INT_MAX);
        int ans = 0;
        for (int i = 0; i < len; i++){
            int h = envelopes[i][1];
            // 如果h不是最大的，那么就尝试修改tail数组，尽可能缩小tail里面的值
            // 寻找到第一个大于等于h的数，并且替代他
            int l = 0;
            int r = tail.size();
            int mid;
            while (l<r){
                mid = (l+r)/2;
                if (tail[mid] == h){
                    l = mid; // 注意这个！
                    break;
                } else if (tail[mid] < h){
                    l = mid + 1;
                } else if (tail[mid] > h){
                    r = mid;
                }
            }
            // 一定能找到，结果存在l中。
            tail[l] = h;
            ans = max(ans, l);
        }
        return ans+1;
    }
};
// @lc code=end

int main(){
    vector<vector<int> > test = {{5,4}, {6,4},{6,7},{2,3}};
    cout << Solution{}.maxEnvelopes(test) << endl;;
}
