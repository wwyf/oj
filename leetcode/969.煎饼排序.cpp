/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for (int i = A.size()-1; i >= 0; i--){
            // make the biggest num of A[0:i+1] to the A[i]
            auto max_it = max_element(A.begin(), A.begin()+i+1);
            auto max_index = max_it - A.begin();
            if (max_index == i){
                continue;
            } else if (max_index == 0){
                ans.push_back(i+1);
                for (int j = 0; j <= (i-1)/2; j++){
                    swap(A[j], A[i-j]);
                }
            } else {
                ans.push_back(max_index+1);
                for (int j = 0; j <= (max_index-1)/2; j++){
                    swap(A[j], A[max_index-j]);
                }
                ans.push_back(i+1);
                for (int j = 0; j <= (i-1)/2; j++){
                    swap(A[j], A[i-j]);
                }
            }
            // for (auto n : A){
            //     cout << " " << n;
            // }
            // cout << endl;
        }
        return ans;
    }
};
// @lc code=end

