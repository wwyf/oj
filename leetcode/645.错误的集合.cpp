/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */
/*
1. 先排序，再遍历寻找，问题：如果缺失的数在末尾，就找不到了
2. unordered_map遍历一遍，寻找值为0和值为2的key

*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = 0;
        int miss = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[abs(nums[i])-1] < 0){
                dup = abs(nums[i]);
            } else {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                miss = i+1;
                break;
            }
        }
        return vector<int>{dup, miss}; 
    }
};
// @lc code=end

int main(){
    auto input = vector<int>{1,2,2,4};
    auto v = Solution{}.findErrorNums(input) ;
    for (int i : v){
        cout << i << endl;
    }
}