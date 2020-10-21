/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int heapSize = len;
        // 叶子结点不用管，所以/2
        for (int i = heapSize/2; i>= 0; i--){
            maxHeap(nums, i, heapSize);
        }
        for (int i = 0; i < k-1; i++){
            swap(nums[0], nums[heapSize-1]);
            heapSize--;
            maxHeap(nums, 0, heapSize);
        }

        return nums[0];
    }

    void maxHeap(vector<int>& nums, int index, int heapSize){
        int l = index*2+1;
        int r = index*2+2;
        int largest = index;
        if (l < heapSize && nums[l] > nums[largest]){
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]){
            largest = r;
        }

        if (largest != index){
            swap(nums[index], nums[largest]);
            maxHeap(nums, largest, heapSize);
        }

    }
};
// @lc code=end

