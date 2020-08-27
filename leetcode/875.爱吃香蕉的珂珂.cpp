/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int li = 1;
        int ri = *max_element(piles.begin(), piles.end());
        while(li <= ri){
            int mid = (ri-li)/2 + li;
            int t = check(piles, mid);
            if (t < H){
                ri = mid-1;
            } else if (t > H){
                li = mid+1;
            } else {
                return mid;
            }
        }
        return li;
    }
    int check(vector<int>& piles, int K){
        int t = 0;
        for (auto p : piles){
            t += (p+K-1)/K;
        }
        return t;
    }
};
// @lc code=end

