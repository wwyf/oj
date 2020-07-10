/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

/*

1. 使用map，超时了
2. 使用数组，搞定，记得有个质数筛的算法。

*/


#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2){
            return 0;
        }
        int ans = n-2;
        vector<int> isDouble(n, 0); // 优化2
        // unordered_map<int, bool> isDouble;
        int upbound = sqrt(n);
        for (int i = 2; i <= upbound; i++){
            if (isDouble[i] == 0){
                // not found
                int s = i*i; // 优化1
                while(s < n){
                    if (isDouble[s] == 0){
                        ans--;
                        isDouble[s] = 1;
                    }
                    s += i;
                }
            }
        }
        return ans;
    }

    int countPrimes2(int n) {
        if (n <= 2){
            return 0;
        }
        int ans = n-2;
        unordered_map<int, bool> isDouble;
        int upbound = sqrt(n);
        for (int i = 2; i <= upbound; i++){
            if (isDouble.find(i) == isDouble.end()){
                // not found
                int s = i+i;
                while(s < n){
                    if (isDouble.find(s) == isDouble.end()){
                        ans--;
                        isDouble[s] = true;
                    }
                    s += i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

