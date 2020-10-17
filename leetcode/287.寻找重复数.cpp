/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int fast = 0, slow = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        int finder = 0;
        while(true){
            finder = nums[finder];
            slow = nums[slow];
            if(slow == finder)
                break;        
        }
        return slow;
    }
};

// 作者：zjczxz
// 链接：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int len = nums.size();
//         int l = 1;
//         int r = len;
//         int mid = 0;
//         int ans = 0;

//         while(l < r){
//             mid = l + (r-l)/2;

//             // get cnt[mid]
//             int cnt = 0;
//             for (int i = 0; i < len; i++){
//                 if (nums[i] <= mid){
//                     cnt++;
//                 }
//             }

//             if (cnt > mid){
//                 r = mid;
//                 ans = mid;
//             } else if (cnt <= mid ){
//                 l = mid+1;
//             }
            
//         }

//         // 寻找到第一个cnt[i] > i的位置

//         return ans;

//     }
// };
// @lc code=end

