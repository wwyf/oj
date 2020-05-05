/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        maxLengthWithLimit(arr, 0, "", result);
        return result;
    }
    void maxLengthWithLimit(vector<string>& arr, int limit, string currentStr, int & result){
        // limit 从0 到 len
        // 递归结束条件
        if(arr.size() == limit){
            if (unique(currentStr)){
                result = max(result, int(currentStr.size()));
            } 
            return;
        }
        // 遍历有arr[limit]开头的情况
        if (unique(arr[limit]+currentStr)){
            maxLengthWithLimit(arr, limit+1, arr[limit]+currentStr, result);
        }
        // 遍历没有arr[limit]开头的情况
        if (unique(currentStr)){
            maxLengthWithLimit(arr, limit+1, currentStr, result);
        }
    }
    bool unique(string s){
        int hash[256] = {0};
        for (auto c : s){
            if (hash[c] == 1){
                return false;
            }
            else {
                hash[c] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

