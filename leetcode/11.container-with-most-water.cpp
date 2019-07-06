/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (44.50%)
 * Likes:    3452
 * Dislikes: 453
 * Total Accepted:    394.5K
 * Total Submissions: 871.7K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution1 {
// 粗暴遍历，倒序了也没什么区别
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        for (int i = 0; i < len-1; i++){
            for (int j = i+1; j < len; j++){
                int r = std::min(height[i],height[j])*(j-i);
                if (r > ans){
                    ans = r;
                }
            }
        }
        return ans;
    }
};

class Solution {
// 优雅遍历
// https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
// 这个解释妙！！！！
// 还是要多想想
// 最重要的思想是：对于(l,r)对，如果height[l] < height[r]，那么r柱子向左移所得到的池子一定更小。
// 明确到这一点后，计算量大大减小。
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len-1;
        int ans = 0;
        while (l < r){
            ans = std::max(std::min(height[l], height[r])*(r-l), ans);
            if (height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};

