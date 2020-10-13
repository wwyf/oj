/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int len = nums.size();
        while(j < len){
            if (i == j && nums[i] != 0){
                i++;
                j++;
            }
            else if (i == j && nums[i] == 0){
                // find next available j
                while(j < len && nums[j] == 0){
                    j++;
                }
                if (j >= len){
                    break;
                }else{
                    swap(nums[i], nums[j]);
                }
                i++;
            } else if (nums[i] != 0 && i < j){
                i++;
            } else if (nums[i] == 0){
                while(j < len && nums[j] == 0){
                    j++;
                }
                if (j >= len){
                    break;
                } else {
                    swap(nums[i], nums[j]);
                }
                i++;
            }
        }
    }
};
// @lc code=end

