/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int find_root(int x, vector<int> & pars){
        int root = x;
        while(pars[root] != -1){
            root = pars[root];
        }
        return root;
    }
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        for (int i = 0; i < row.size(); i++){
            row[i] /= 2;
        }
        set<pair<int,int>> t;
        unordered_map<int , int> buckets;
        for (int i = 0; i < row.size(); i+=2){
            if (row[i] == row[i+1]){
                continue;
            }
            int min_num = min(row[i], row[i+1]);
            int max_num = max(row[i], row[i+1]);
            if (t.find(pair<int,int>(min_num, max_num)) != t.end()){
                ans++;
                cout << ans << endl;
                t.erase(pair<int,int>(min_num, max_num));
            } else {
                t.insert(pair<int,int>(min_num, max_num));
            }
        }
        int circle = 0;
        vector<int> pars(row.size()/2, -1);
        for (auto p : t){
            int x1 = p.first;
            int x2 = p.second;
            int x1_root = find_root(x1, pars);
            int x2_root = find_root(x2, pars);
            if (x1_root == x2_root){
                circle++;
            } else {
                pars[x1_root] = x2_root;
            }
        }
        if (t.size() > 0){
            ans += t.size()-circle;
            // cout << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    vector<int> t = {10,7,4,2,3,0,9,11,1,5,6,8};
    auto ans = Solution{}.minSwapsCouples(t);
    cout << ans << endl;
}

