/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
struct P{
    int x;
    int y;
    int action; // 1:live 0:die
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<P> ops;
        int h = board.size();
        int w = board[0].size();
        int locs[8][2] = {
            {-1,-1}, {-1,0}, {-1,1}, 
            {0, -1}, {0 ,1}, 
            {1, -1}, {1 ,0}, {1,1}
        };
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                // board[i][j]
                int live_count = 0;
                for (int k = 0; k < 8; k++){
                    int new_i = i+locs[k][0];
                    int new_j = j+locs[k][1];
                    if (0 <= new_i && new_i < h && 0 <= new_j && new_j< w){
                        if (board[new_i][new_j] == 1){
                            live_count++;
                        }
                    }
                }
                if (live_count < 2){
                    ops.push_back({i,j,0});
                } else if (live_count == 3){
                    ops.push_back({i,j,1});
                } else if (live_count > 3){
                    ops.push_back({i,j,0});
                }
            }
        }
        for (auto op : ops){
            board[op.x][op.y] = op.action; 
        }
        return ;
        
    }
};
// @lc code=end

