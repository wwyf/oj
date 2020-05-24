/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 特殊情况， 需要判断k=0的情况
        int numsLen = nums.size();
        if (numsLen <= 1){
            return false;
        }
        // step 1 计算前缀和
        // step 2 并判断前缀和是否是k的倍数
        vector<int> frontSum;
        frontSum.push_back(0);
        for (auto num : nums){
            frontSum.push_back(num + frontSum.back());
        }
        // step 3 判断遍历前缀和的差并判断
        int len = frontSum.size();
        // 遍历方式：大循环遍历被减数，小循环遍历减数
        for (int i = 0; i < len-2; i++){
            for (int j = i+2; j < len; j++){
                if (k == 0){
                    if((frontSum[j]-frontSum[i]) == 0){
                        return true;
                    }
                } else if ((frontSum[j]-frontSum[i])%k == 0){
                    return true;
                }
            }   
        }
        return false;
    }
};
// @lc code=end

