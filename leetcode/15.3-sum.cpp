/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.99%)
 * Likes:    4037
 * Dislikes: 462
 * Total Accepted:    582.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// class Solution {
// // naive 做法 , 暴力搜索
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         if (len <= 2){
//             return ans;
//         }
//         for (int i = 0; i < len-2; i++){
//             for (int j = i+1; j < len-1; j++){
//                 for (int k = j+1; k < len; k++){
//                     if (nums[i] + nums[j] + nums[k] == 0){
//                         int anslen = ans.size();
//                         int flag = 1;
//                         for (int ii = 0; ii < anslen; ii++){
//                             if (nums[i] == ans[ii][0] && nums[j] == ans[ii][1] && nums[k] == ans[ii][2]){
//                                 flag = 0;
//                                 break;
//                             }
//                         }
//                         if (flag){
//                             ans.insert(ans.end(), vector<int>({nums[i], nums[j], nums[k]}));  
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
// // naive 2 去掉了一点点搜索空间
// /*
// × Time Limit Exceeded
// × 311/~13 cases passed (N/A)
//  */
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         if (len <= 2){
//             return ans;
//         }
//         for (int i = 0; i < len-2; i++){
//             for (int j = i+1; j < len-1; j++){
//                 for (int k = j+1; k < len; k++){
//                     if (nums[i] + nums[j] + nums[k] == 0){
//                         int anslen = ans.size();
//                         int flag = 1;
//                         for (int ii = 0; ii < anslen; ii++){
//                             if (nums[i] == ans[ii][0] && nums[j] == ans[ii][1] && nums[k] == ans[ii][2]){
//                                 flag = 0;
//                                 break;
//                             }
//                         }
//                         if (flag){
//                             ans.insert(ans.end(), vector<int>({nums[i], nums[j], nums[k]}));  
//                         }
//                         break; // 加了这个
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// // naive 3 继续去掉了一点点搜索空间，还是很慢？
// /*
// × Time Limit Exceeded
// × 311/~13 cases passed (N/A)
//  */
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         if (len <= 2){
//             return ans;
//         }
//         for (int i = 0; i < len-2; i++){
//             if(i >= 1 && nums[i] == nums[i-1]){
//                 continue;
//             }
//             for (int j = i+1; j < len-1; j++){
//                 if (j >= i+1+1 && nums[j] == nums[j-1]){
//                     continue;
//                 }
//                 for (int k = j+1; k < len; k++){
//                     if (nums[i] + nums[j] + nums[k] == 0){
//                         int anslen = ans.size();
//                         int flag = 1;
//                         // for (int ii = 0; ii < anslen; ii++){
//                         //     if (nums[i] == ans[ii][0] && nums[j] == ans[ii][1] && nums[k] == ans[ii][2]){
//                         //         flag = 0;
//                         //         break;
//                         //     }
//                         // }
//                         if (flag){
//                             ans.insert(ans.end(), vector<int>({nums[i], nums[j], nums[k]}));  
//                         }
//                         break; // 加了这个
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };





// class Solution {
// // naive 4 将最里面的for循环改成二分搜索吧
// /*
// √ Accepted
//   √ 313/313 cases passed (252 ms)
//   √ Your runtime beats 12.34 % of cpp submissions
//   √ Your memory usage beats 99.89 % of cpp submissions (14.4 MB)
//  */
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         if (len <= 2){
//             return ans;
//         }
//         for (int i = 0; i < len-2; i++){
//             if(i >= 1 && nums[i] == nums[i-1]){
//                 continue;
//             }
//             for (int j = i+1; j < len-1; j++){
//                 if (j >= i+1+1 && nums[j] == nums[j-1]){
//                     continue;
//                 }
//                 int third_num = 0 - nums[i] - nums[j];
//                 // 在 nums[j+1] 到 nums[len-1] 之间 搜索 third_num 这个数，找到了就ok，找不到就凉凉。
//                 int l = j+1;
//                 int r = len;
//                 while ( l < r){
//                     int mid = (l+r)/2;
//                     if (nums[mid] == third_num){
//                         ans.insert(ans.end(), vector<int>({nums[i], nums[j], third_num}));
//                         break;
//                     }
//                     else{
//                         if (nums[mid] < third_num){
//                             l = mid+1;
//                         }
//                         else {
//                             r = mid;
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// // naive 5 用个表记录每个数的位置吧。 更菜了。瓶颈是什么？？
// /*
// √ Accepted
//   √ 313/313 cases passed (404 ms)
//   √ Your runtime beats 7.17 % of cpp submissions
//   √ Your memory usage beats 48.98 % of cpp submissions (15.2 MB)
//  */
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int len = nums.size();
//         sort(nums.begin(), nums.end());
//         map<int, int> index;
//         // 记录最后出现的index
//         for (int i = 0; i < len; i++){
//             index[nums[i]] = i;
//         }
//         vector<vector<int>> ans;
//         if (len <= 2){
//             return ans;
//         }
//         for (int i = 0; i < len-2; i++){
//             if(i >= 1 && nums[i] == nums[i-1]){
//                 continue;
//             }
//             for (int j = i+1; j < len-1; j++){
//                 if (j >= i+1+1 && nums[j] == nums[j-1]){
//                     continue;
//                 }
//                 int third_num = 0 - nums[i] - nums[j];
//                 // 在 nums[j+1] 到 nums[len-1] 之间 搜索 third_num 这个数，找到了就ok，找不到就凉凉。
//                 if(index.find(third_num) != index.end() && index[third_num] >= j+1){
//                     ans.insert(ans.end(), vector<int>({nums[i], nums[j], third_num}));
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 学习大佬写法

// class Solution
// {
//     // 亮点：
//     // 1. 搜索方向：左右开弓
//     // 2. 减少了搜索量：第二个数和第三个数之间存在制约关系，因此将这里本身可能存在的n^2搜索变成了O(n)的搜索，这是最关键的！
//     /*
// √ Accepted
//   √ 313/313 cases passed (96 ms)
//   √ Your runtime beats 87.6 % of cpp submissions
//   √ Your memory usage beats 41.03 % of cpp submissions (15.7 MB)
//  */
// public:
//     vector<vector<int>> threeSum(vector<int> &num)
//     {
//         vector<vector<int>> res;
//         std::sort(num.begin(), num.end());
//         for (int i = 0; i < num.size(); i++)
//         {

//             int target = -num[i];
//             int front = i + 1;
//             int back = num.size() - 1;

//             while (front < back)
//             {

//                 int sum = num[front] + num[back];

//                 // Finding answer which start from number num[i]
//                 if (sum < target)
//                     front++;

//                 else if (sum > target)
//                     back--;

//                 else
//                 {
//                     vector<int> triplet(3, 0);
//                     triplet[0] = num[i];
//                     triplet[1] = num[front];
//                     triplet[2] = num[back];
//                     res.push_back(triplet);

//                     // Processing duplicates of Number 2
//                     // Rolling the front pointer to the next different number forwards
//                     while (front < back && num[front] == triplet[1])
//                         front++;

//                     // Processing duplicates of Number 3
//                     // Rolling the back pointer to the next different number backwards
//                     while (front < back && num[back] == triplet[2])
//                         back--;
//                 }
//             }

//             // Processing duplicates of Number 1
//             while (i + 1 < num.size() && num[i + 1] == num[i])
//                 i++;
//         }

//         return res;
//     }
// };
