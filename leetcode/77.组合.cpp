/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k > n){
            return ans;
        }
        if (k == n){
            vector<int> ans1;
            for (int i = 1; i <= n; i++){
                ans1.push_back(i);
            }
            ans.push_back(ans1);
            return ans;
        }
        if (k == 1){
            for (int i = 1; i <= n; i++){
                ans.push_back(vector<int>{i});
            }
            return ans;
        }
        // 1 < k < n
        // f(n-1, k-1)  f(n-1, k)
        auto a1 = combine(n-1, k); // not use n
        auto a2 = combine(n-1, k-1); // use n
        for (int i = 0; i < a2.size(); i++){
            a2[i].push_back(n);
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return  a1;
    }
};
// @lc code=end

int main(){
    auto a = Solution{}.combine(4,2);
    for (auto i : a){
        for (auto j : i){
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}

