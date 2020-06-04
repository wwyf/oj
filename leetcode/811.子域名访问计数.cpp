/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        for(int i = 0; i < cpdomains.size(); i++){
            int times = 0;
            int j = 0;
            for(j = 0; j < cpdomains[i].length(); j++){
                if(isdigit(cpdomains[i][j])){
                    times = times*10 + cpdomains[i][j] - '0';
                }
                else{
                    break;
                }
            }
            string address = "";
            for(int k = cpdomains[i].length()- 1; k >= j; k--){
                if(cpdomains[i][k] == '.'){
                    count[address] += times;
                    address = '.' + address;
                }
                else if(isalpha(cpdomains[i][k])){
                    address = cpdomains[i][k] + address;
                }
            }
            count[address] += times;
        }
        vector<string> res;
        for(auto i = count.begin(); i != count.end(); i++){
            string cur = "";
            cur = to_string(i -> second) + " " + i -> first;
            res.push_back(cur);
        }
        return res;
    }
};
// @lc code=end

