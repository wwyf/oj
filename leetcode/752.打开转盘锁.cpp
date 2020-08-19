/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_set<string> isTried;
    unordered_set<string> isDeadend;

    struct node{
        string s;
        int d;
    };
    int openLock(vector<string>& deadends, string target) {
        for (auto s : deadends){
            isDeadend.insert(s);
        }
        int ans = -1;
        const int steps[2] = {1,-1};
        queue<node> q;
        q.push(node{"0000", 0});
    
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            if (cur.s == target){
                return cur.d;
            }

            if(isDeadend.find(cur.s) == isDeadend.end() && isTried.find(cur.s) == isTried.end()){
                isTried.insert(cur.s);
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 2; j++){
                        string n = cur.s;
                        // bug : -1%10 == -1， 这里加个10就可以了
                        n[i] = ((n[i]-'0')+steps[j]+10)%10 + '0';
                        q.push(node{n, cur.d+1});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end


int main(){
    vector<string> ss={"8888"};

    cout << Solution{}.openLock(ss, "0009") << endl;
}

