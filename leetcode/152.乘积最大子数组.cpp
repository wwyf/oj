/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> dpMax(len), dpMin(len);
        dpMax[0] = nums[0]; dpMin[0] = nums[0];
        for (int i = 1; i < len; i++){
            dpMax[i] = max(dpMax[i-1]*nums[i], max(dpMin[i-1]*nums[i], nums[i]));
            dpMin[i] = min(dpMax[i-1]*nums[i], min(dpMin[i-1]*nums[i], nums[i]));
        }
        return *max_element(dpMax.begin(), dpMax.end());

    }
};
// @lc code=end

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int dpMax, dpMin, ans;
        dpMax = nums[0];
        dpMin = nums[0];
        ans = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int tmax = dpMax, tmin = dpMin;
            dpMax = max(tmax*nums[i], max(tmin*nums[i], nums[i]));
            dpMin = min(tmax*nums[i], min(tmin*nums[i], nums[i]));
            ans = max(ans, dpMax);
        }
        return ans;
    }
};


//bug

class SolutionBug {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMax, dpMin;
        // 没想到啊，一开始push的这个1，竟然在最后成为了bug
        dpMax.push_back(1);
        dpMin.push_back(1);
        for (auto num : nums){
            int dpMax_ = dpMax.back();
            int dpMin_ = dpMin.back();
            cout << "dpMax_:" << dpMax_ << endl;
            cout << "dpMin_:" << dpMin_ << endl;
            dpMax.push_back(max(dpMax_*num, max(dpMin_*num, num)));
            dpMin.push_back(min(dpMax_*num, min(dpMin_*num, num)));
        }
        return *max_element(dpMax.begin(), dpMax.end());

    }
};
int main(){
    vector<int> nums{-2, 0, -1};
    cout << SolutionBug{}.maxProduct(nums) << endl;
}
