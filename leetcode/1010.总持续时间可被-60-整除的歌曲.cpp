/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */


// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size();
        int c[61];
        for (int i = 0 ; i < 61; i++){
            c[i] = 0;
        }
        if (len <= 1){
            return 0;
        }
        for (int i = 0; i < len; i++){
            int num = time[i] % 60;
            c[num]++;
        }
        int sum = 0;
        for (int i = 1; i <= 29; i++){
            sum += c[i]*c[60-i];
        }
        return sum+c2(c[0])+c2(c[30]);
        // return sum;
        // return c2(c[0]);
        // return c2(c[30]);
    }
    int c2(int num){
        if (num <= 1){
            return 0;
        }
        return num*(num-1)/2;
    }
};
// @lc code=end

