/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

/*
2020-8-3 09:44:26
2020-8-3 10:09:23

*/

#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
/*
题解：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-de-shu-zi-2/
技巧：在原来的数组上用正负号做标记，记录数字是否出现
妙啊

Accepted

34/34 cases passed (128 ms)

Your runtime beats 42.94 % of cpp submissions

Your memory usage beats 20.64 % of cpp submissions (32.5 MB)

*/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    // vector<int> findDisappearedNumbers_05(vector<int>& nums) {
        vector<int> ans;
        // 做标记
        for (int i = 0; i < nums.size(); i++){
            int abs_num = abs(nums[i]);
            nums[abs_num-1] = - abs(nums[abs_num-1]);
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
/*

Accepted

34/34 cases passed (136 ms)

Your runtime beats 30.57 % of cpp submissions

Your memory usage beats 24.77 % of cpp submissions (32.4 MB)
*/
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> findDisappearedNumbers_04(vector<int>& nums) {
        vector<int> ans;
        vector<bool> s(nums.size()+1, false);
        for (int i = 0; i < nums.size(); i++){
            s[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size(); i++){
            // find i
            bool isFound = s[i];
            if (!isFound){
                ans.push_back(i);
            }
        }
        return ans;
    }
/*
Accepted

34/34 cases passed (352 ms)

Your runtime beats 5.12 % of cpp submissions

Your memory usage beats 5.05 % of cpp submissions (45.5 MB)
*/
    vector<int> findDisappearedNumbers_03(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        for (int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        for (int i = 1; i <= nums.size(); i++){
            // find i
            bool isFound = s.find(i) != s.end();
            if (!isFound){
                ans.push_back(i);
            }
        }
        return ans;
    }
/*
Accepted

34/34 cases passed (216 ms)

Your runtime beats 14.27 % of cpp submissions

Your memory usage beats 62.39 % of cpp submissions (32.2 MB)
*/
    vector<int> findDisappearedNumbers_02(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int ni = 0;
        for (int i = 1; i <= nums.size(); i++){
            // find i
            while(ni < nums.size() && nums[ni] < i){
                ni++;
            }
            if (ni >= nums.size() || nums[ni] != i){
                ans.push_back(i);
            }else{
                ni++;
            }
        }
        return ans;
    }

    // TLE
    vector<int> findDisappearedNumbers_01(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int ni = 0;
        for (int i = 1; i <= nums.size() && ni < nums.size(); i++){
            // find i
            bool isFound = false;
            for (int j = 0; j < nums.size(); j++){
                if (nums[j] == i){
                    isFound = true;
                    break;
                }
            }
            if (!isFound){
                ans.push_back(i);
            }
        }
        return ans;
    }

};
// @lc code=end

