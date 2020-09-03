/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

/*
2020-9-3 11:55:51

2020-9-3 12:00:13
ok

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()){
            return 0;
        }
        int ans = 0;
        int lowest = prices[0];
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > lowest){
                ans = max(ans, prices[i]-lowest); 
            } else if (lowest > prices[i]){
                lowest = min(lowest, prices[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

