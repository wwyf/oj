/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.34%)
 * Likes:    4531
 * Dislikes: 635
 * Total Accepted:    457.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include<vector>
using namespace std;

class Solution1 {
// ac ! 
// 具体思路是两个数组同时去掉相同个数，然后就变成了求子问题的中位数。
// 好像不是很稳定，有时击败了90+有时击败了10+
// findMedian 将vector改成了普通数组之后，快了不少，内存占用也小了一点
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        return findMedianR(nums1, nums2, 0, len1, 0, len2);
    }

    double findMedianR(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2){
        int len1 = r1-l1;
        int len2 = r2-l2;
        if (len1 <= 2 || len2 <= 2){
            return findMedian(nums1, nums2, l1, r1, l2, r2);
        }
        int m1 = (len1-1)/2;
        int m2 = (len2-1)/2;
        int unit = min(m1, m2);
        if (nums1[l1+m1] < nums2[l2+m2]){
            return findMedianR(nums1, nums2, l1+unit, r1, l2, r2-unit);
        }
        else{
            return findMedianR(nums1, nums2, l1, r1-unit, l2+unit, r2);
        }
    }

    double findMedian(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2){
        // call it when the length of vector <= 2.
        int len1 = r1-l1;
        int len2 = r2-l2;
        int nums[1000];
        int len = 0;
        // sort
        int i1 = l1, i2 = l2;
        while (i1 < r1 && i2 < r2){
            if (nums1[i1] < nums2[i2]){
                nums[len] = nums1[i1];
                len++;
                i1++;
            }
            else{
                nums[len] = nums2[i2];
                len++;
                i2++;
            }
        }
        while (i1 < r1){
            nums[len] = nums1[i1];
            len++;
            i1++;
        }
        while (i2 < r2){
            nums[len] = nums2[i2];
            len++;
            i2++;
        }
        // find Median
        if (len % 2 == 1){
            return nums[len/2];
        }
        else{
            return (nums[len/2-1]+nums[len/2])/2.0;
        }
    }
};


class Solution {
// ac ! 
// 具体思路是两个数组同时去掉相同个数，然后就变成了求子问题的中位数。
// 换成循环之后，内存占用小了一些。
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0;
        int r1 = nums1.size();
        int l2 = 0;
        int r2 = nums2.size();
        while (r1-l1 > 2 && r2-l2 > 2){
            int len1 = r1-l1;
            int len2 = r2-l2;
            int m1 = (len1-1)/2;
            int m2 = (len2-1)/2;
            int unit = min(m1, m2);
            if (nums1[l1+m1] < nums2[l2+m2]){
                l1 = l1 + unit;
                r2 = r2 - unit;
            }
            else{
                r1 = r1 - unit;
                l2 = l2 + unit;
            }
        }
        return findMedian(nums1, nums2, l1, r1, l2, r2);
    }

    double findMedian(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2){
        // call it when the length of vector <= 2.
        int len1 = r1-l1;
        int len2 = r2-l2;
        int nums[1000];
        int len = 0;
        // sort
        int i1 = l1, i2 = l2;
        while (i1 < r1 && i2 < r2){
            if (nums1[i1] < nums2[i2]){
                nums[len] = nums1[i1];
                len++;
                i1++;
            }
            else{
                nums[len] = nums2[i2];
                len++;
                i2++;
            }
        }
        while (i1 < r1){
            nums[len] = nums1[i1];
            len++;
            i1++;
        }
        while (i2 < r2){
            nums[len] = nums2[i2];
            len++;
            i2++;
        }
        // find Median
        if (len % 2 == 1){
            return nums[len/2];
        }
        else{
            return (nums[len/2-1]+nums[len/2])/2.0;
        }
    }
};
