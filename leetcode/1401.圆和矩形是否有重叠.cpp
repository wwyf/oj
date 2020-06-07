/*
 * @lc app=leetcode.cn id=1401 lang=cpp
 *
 * [1401] 圆和矩形是否有重叠
 */

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx, dy;
        if (x_center < x1){
            dx = x1 - x_center;
        } else if (x_center > x2){
            dx = x_center - x2;
        } else {
            dx = 0;
        }
        if (y_center < y1){
            dy = y1-y_center;
        } else if (y_center > y2){
            dy = y_center - y2;
        } else {
            dy = 0;
        }
        return dx*dx+dy*dy <= radius*radius;
    }
};
// @lc code=end

