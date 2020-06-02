/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end){
            return 0;
        }
        set<string> used;
        used.insert(start);
        return minMutationR(start, end, bank, used);
    }
    int minMutationR(string start, string end, vector<string>& bank, set<string>& used){
        auto nextMutations = getNextMutation(start, bank, used);
        if (nextMutations.empty()) return -1;
        int ans = INT_MAX;
        for (auto m : nextMutations){
            if (m == end){
                return 1;
            } else{
                used.insert(m);
                int nextAns = minMutationR(m, end, bank, used);
                if (nextAns != -1){
                    ans = min(ans, nextAns+1);
                }
                used.erase(m);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
    vector<string> getNextMutation(string & start, vector<string>& bank, set<string>& used){
        vector<string> ans;
        for (auto s : bank){
            int diff = 0;
            for (int i = 0; i < 8; i++){
                if (start[i] != s[i]){
                    diff++;
                }
            }
            if (diff == 1 && (used.find(s) == used.end())){
                // only insert str that have not been used
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};
// @lc code=end

