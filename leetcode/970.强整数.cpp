/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // 尝试取得x、y 的幂的上下限
        // 获得小于bound的所有x/y的幂的数
        vector<int> xm; xm.push_back(1);
        vector<int> ym; ym.push_back(1);
        vector<int> ans;
        int cur = x;
        if (x != 1 ){
            while (cur <= bound ){
                xm.push_back(cur);
                cur *= x;
            }
        }
        cur = y;
        if (y != 1 ){
            while (cur <= bound ){
                ym.push_back(cur);
                cur *= y;
            }
        }
        for (auto xi : xm){
            for (auto yi : ym){
                if (xi + yi <= bound){
                    if (find(ans.begin(), ans.end(), xi+yi) == ans.end()){
                        ans.push_back(xi+yi);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

