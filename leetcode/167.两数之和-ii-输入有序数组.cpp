/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

/*
1. 使用map, 没有用到有序的特性
2. 二分搜索？可行是可行
3. 双指针！标答，太强了，用上了有序的特性，时间是O(n)， 空间是O(1)
```
17/17 cases passed (16 ms)
Your runtime beats 20.68 % of cpp submissions
Your memory usage beats 62.07 % of cpp submissions (9.4 MB)
```
*/

#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    // 双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if (sum > target){
                r--;
            } else if (sum < target){
                l++;
            } else {
                return vector<int>{l+1,r+1};
            }
        }
        return vector<int>{};
    }
    vector<int> twoSum1(vector<int>& numbers, int target) {
        unordered_map<int, int> k2i;
        for (int i = 0 ; i < numbers.size(); i++){
            k2i[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); i++){
            int n1 = numbers[i];
            int n2 = target - n1;
            if (k2i.find(n2) != k2i.end()){
                return vector<int>{i+1, k2i[n2]+1};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

