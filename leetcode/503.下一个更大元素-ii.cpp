/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
/*

*/

#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), 0);
        int n = nums.size();
        for (int i = 2*n-1; i >= 0; i--){
            // 栈的含义：数字nums[i]后面组成的一个单调递增序列
            // 先把小于等于nums[i]的去掉
            while(!s.empty() && nums[i%n] >= s.top()){
                s.pop();
            }
            ans[i%n] = s.empty()? -1 : s.top();
            s.push(nums[i%n]);
        }
        return ans;
    }
    vector<int> nextGreaterElements_2(vector<int>& nums) {
        vector<int> ans(nums.size(), INT_MIN);
        for (int i = nums.size()-1; i >= 0; i--){
            int j = 1;
            bool isFound = false;
            int cur = (i+j)%nums.size();
            while (j < nums.size() && nums[cur] <= nums[i]){
                if (nums[i] < ans[cur]){
                    ans[i] = ans[cur];
                    isFound = true;
                    break;
                }
                j++;
                cur = (i+j)%nums.size();
            }
            if (isFound == false) {
                if (j != nums.size()){
                    ans[i] = nums[cur];
                } else {
                    ans[i] = -1;
                }
            }
        }
        return ans;
    }
    vector<int> nextGreaterElements_1(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for (int i = nums.size()-1; i >= 0; i--){
            if (i != nums.size()-1){
                if (nums[i] >= nums[i+1] && nums[i] < ans[i+1]){
                    ans[i] = ans[i+1];
                    continue;
                }
            }
            for (int j = 1; j < nums.size(); j++){
                int cur = (i + j) % nums.size();
                if (nums[cur] > nums[i]){
                    ans[i] = nums[cur];
                    break;
                }
            }
        }
        return ans;
    }
    vector<int> nextGreaterElements_0(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++){
            for (int j = 1; j < nums.size(); j++){
                int cur = (i + j) % nums.size();
                if (nums[cur] > nums[i]){
                    ans[i] = nums[cur];
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

