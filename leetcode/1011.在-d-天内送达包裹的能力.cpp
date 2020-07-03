/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int prefixSums[50004];
    int shipWithinDays(vector<int>& weights, int D) {
        int len = weights.size();
        int maxW = 0;
        int sumW = 0;
        for (int i = 0 ; i < len; i++){
            sumW += weights[i];
            if (weights[i] > maxW){
                maxW = weights[i];
            }
        }
        // 在[maxW, sumW]范围内二分搜索
        // 随着k的单调增加，结果是完全二分的
        int l = maxW;
        int r = sumW;
        int mid = (maxW+sumW)/2;
        while(l < r){
            if(ship(weights, D, mid)){
                r = mid;
            }else{
                l = mid+1; // 加1十分重要
            }
            //mid = (l+r)/2;
            mid = l + (r-l)/2; //  避免溢出
        }
        return l;
    }
    bool ship(vector<int>&weights, int D, int K){
        int s = 0;
        int count = 1;
        int len = weights.size();
        for (int i = 0; i < len; i++){
            if (s+weights[i] <= K){
                s+=weights[i];
            } else{
                count++;
                s = weights[i];
                if (count > D){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

