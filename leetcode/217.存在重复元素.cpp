/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 2020-11-09 10:12:18
        unordered_set<int> s;
        for (auto n : nums){
            if (s.find(n) != s.end()){
                return true;
            }
            s.insert(n);
        }
        return false;
        // 2020-11-09 10:14:31
        /*
            Accepted
            18/18 cases passed (68 ms)
            Your runtime beats 81.87 % of cpp submissions
            Your memory usage beats 36.29 % of cpp submissions (19.4 MB)
        */


    }
};
// @lc code=end

