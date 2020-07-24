/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */
#include <cmath>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int pow(int base, int mi){
        int ans = 1;
        while (mi--){
            ans = ((ans % 1337) * (base % 1337) ) % 1337;
        }
        return ans % 1337;
    }
    int superPow(int a, vector<int>& b) {
        int len = b.size();
        if (len <= 0){
            return 1;
        }
        return superPow(a, b, len-1);

    }
    int superPow(int a, vector<int>& b, int last){
        if (last == 0){
            return pow(a, b[0]);
        }
        return ((pow(a, b[last]) %1337) * (pow(superPow(a, b, last-1), 10) % 1337) ) % 1337;
    }
};
// @lc code=end

