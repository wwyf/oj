/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */


#include <iostream>
#include <vector>
#include <list>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> & l, const vector<int> & r){
            if (l[0] != r[0]){
                // l[0] 降序
                return l[0] > r[0];
            } else{
                // l[1] 升序
                return l[1] < r[1];
            }
        });
        int len = people.size();
        list<vector<int>> tmp;
        for (int i = 0; i < len; i++){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
// @lc code=end

