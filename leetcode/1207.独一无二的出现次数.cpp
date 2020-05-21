/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occurCount;
        map<int, int> uniqueCount;
        for (int i = -1000; i <= 1000; i++){
            occurCount[i] = 0;
            uniqueCount[i] = 0;
        }
        for (auto num : arr){
            occurCount[num]++;
        }
        for (int i = -1000; i <= 1000; i++){
            if (occurCount[i] == 0) continue;
            if (uniqueCount[occurCount[i]] >= 1){
                return false;
            }
            uniqueCount[occurCount[i]]++;
        }
        return true;
    }
};
// @lc code=end

