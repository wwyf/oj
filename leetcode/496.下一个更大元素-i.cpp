/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

/*
2020-8-6 11:50:39
Accepted

17/17 cases passed (8 ms)

Your runtime beats 97.11 % of cpp submissions

Your memory usage beats 74.29 % of cpp submissions (8.8 MB)
2020-8-6 12:02:17
*/
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); i++){
            int biggerNum = -1;
            for (int j = i+1; j < nums2.size(); j++){
                if (nums2[j] > nums2[i]){
                    biggerNum = nums2[j];
                    break;
                }
            }
            m[nums2[i]] = biggerNum;
        }
        vector<int> ans(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++){
            ans[i] = m[nums1[i]];
        }
        return ans;
    }
};
// @lc code=end

