/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int find_root(int pars[], int val){
        if (pars[val] == 0){
            return val;
        }
        return find_root(pars, pars[val]);
    }
    bool equationsPossible(vector<string>& equations) {
        int pars[256] = {0};
        for (auto e : equations){
            if (e[1] == '='){
                auto vl = e[0];
                auto root_l = find_root(pars, int(vl));
                auto vr = e[3];
                auto root_r = find_root(pars, int(vr));
                if (root_l != root_r){
                    pars[root_l] = root_r;
                }
            }
        }
        for (auto e : equations){
            if (e[1] == '!'){
                auto vl = e[0];
                auto root_l = find_root(pars, int(vl));
                auto vr = e[3];
                auto root_r = find_root(pars, int(vr));
                if (root_l == root_r){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

