/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (40.67%)
 * Likes:    1502
 * Dislikes: 3225
 * Total Accepted:    591.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <cassert>
#include <set>
using namespace std;


class Solution {
// 发现条件：已经排好顺序的
// 20 ms
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        if (nums.size() == 1){
            return 1;
        }
        int first = 1;
        for (int i = 1; i < nums.size(); i++){
            // judge nums[i] is duplicate ?
            if (nums[i] > nums[first-1]){
                nums[first] = nums[i];
                first++;
            }
        }
        return first;
    }
};



class Solution2 {
// 32 ms
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        if (nums.size() == 1){
            return 1;
        }
        int first = 0;
        set<int> int_set;
        for (int i = 0; i < nums.size(); i++){
            // judge nums[i] is duplicate ?
            auto find_result = int_set.find(nums[i]);
            if (find_result != int_set.end()){
                // is duplicate
                continue;
            }
            else{
                // 曾经写成了 nums[first] = *find_result;
                nums[first] = nums[i];
                int_set.insert(nums[i]);
                first++;
            }

        }
        return first;
    }
};


class Solution1 {
// 248 ms
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        if (nums.size() == 1){
            return 1;
        }
        int first = 1;
        for (int i = 1; i < nums.size(); i++){
            int isDuplicate = false;
            // judge nums[i] is duplicate ?
            for (int j = 0; j < first; j++){
                if (nums[j] == nums[i]){
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate){
                continue;
            }
            else{
                nums[first] = nums[i];
                first++;
            }
        }
        return first;
    }
};

class Solution_x1 {
    // 错误：不能保留顺序
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        if (nums.size() == 1){
            return 1;
        }
        int first = 1;
        int last = nums.size();
        while (first < last){
            int isDuplicate = false;
            // judge nums[first] is duplicate or not
            for (int i = 0; i < first; i++){
                if (nums[i] == nums[first]){
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate){
                int temp = nums[last-1];
                nums[last-1] = nums[first];
                nums[first] = temp;
                last--;
            }
            else{
                first++;
            }
        }
        return first;
    }
};

// int main(){
//     vector<int> nums = {1,1,2};
//     cout << Solution().removeDuplicates(nums) << endl;
//     return 0;
// }


