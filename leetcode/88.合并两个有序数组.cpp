/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //    2020-8-20 22:10:04 
        for (int i = 0; i < n; i++){
            // nums2[i]
            int insert_index = m;
            while(insert_index-1 >= 0 && nums1[insert_index-1] > nums2[i]){
                insert_index--;
            }
            // move
            for (int j = m-1; j >= insert_index; j--){
                nums1[j+1] = nums1[j];
            }
            nums1[insert_index] = nums2[i];
            m++;
        }
        // 2020-8-20 22:15:04
/*
Accepted

59/59 cases passed (8 ms)

Your runtime beats 30.85 % of cpp submissions

Your memory usage beats 50.65 % of cpp submissions (9.2 MB)
*/
    }
};

/*
看了题解，双指针+从后到前，这种时间复杂度更低！！空间复杂度仍能为O(1)
#TODO
*/
// @lc code=end

