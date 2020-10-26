/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> level;
        vector<string> ans;
        level.insert(s);

        int ok_flag = 0;
        while(!ok_flag && !level.empty()){
            int level_size = level.size();
            set<string> temp;
            for (auto this_s : level){
                if (isValid(this_s)){
                    ans.push_back(this_s);
                    ok_flag = 1;
                } else if (!ok_flag) {
                    for (int j = 0; j < this_s.size(); j++){
                        if (this_s[j] == '(' || this_s[j] == ')'){ // 重要剪枝，只尝试去掉()
                            auto new_s = this_s;
                            new_s.erase(j, 1);
                            temp.insert(new_s);
                        }
                    }
                }
            }
            level = temp;
        }
        return ans;


    }
    bool isValid(string s){
        int cnt = 0;
        for (auto c : s){
            if (c == '('){
                cnt++;
            } else if (c == ')'){
                cnt--;
                if (cnt < 0){
                    return false;
                }
            }
        }
        if (cnt == 0){
            return true;
        } else{
            return false;
        }

    }
};
// @lc code=end

int main(){
    auto vs = Solution().removeInvalidParentheses("()())()");
}