/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }
        int lowest = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i-1] <= prices[i]){
                continue;
            } else {
                // die
                if (lowest < prices[i-1]){
                    ans += prices[i-1]-lowest;
                }
                lowest = prices[i];
            }
        }
        if (lowest < prices[prices.size()-1]){
            ans += prices[prices.size()-1]-lowest;
        }
        return ans;
    }
};
// @lc code=end

