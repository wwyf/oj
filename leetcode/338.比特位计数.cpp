/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for (uint32_t i = 0; i <= num; i++){
            ans.push_back(countBit(i));
        }
        return ans;

    }
    int countBit(uint32_t num){
        int ans = 0;
        while (num){
            // cout << num << endl;
            if ((num & 1) == 1){
                ans++;
            }
            num = num >> 1;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    cout << Solution{}.countBit(3) << endl;
}

