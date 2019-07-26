/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.49%)
 * Likes:    1151
 * Dislikes: 231
 * Total Accepted:    246.3K
 * Total Submissions: 795.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
// 这里的搜索，精妙的剪枝值得学习
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            // 如果这个数字以前搜索过，就跳过
            if(i>0&&nums[i]==nums[i-1]) continue;
            // 如果后面的四个数加起来（最小的结果）大于target，不需要再搜了
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            // 如果当前的数字 加上 最大可能的3个数都比target小的时候，跳过。
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                // 类似的
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                // 开始两个数求和的结果等于target的寻找
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        // 跳过相同的
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        // 跳过相同的
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};
