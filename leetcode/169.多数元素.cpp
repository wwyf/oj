/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> countmap;
        for (auto num : nums){
            countmap[num]++;
            if (countmap[num] >= (len+1)/2){
                return num;
            }
        }
        return 0;
    }
};
// @lc code=end

