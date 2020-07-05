/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */


#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int row = board.size();
        int col = board[0].size();
        int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        for(int i = 0;i<row;i++){
            if(board[i][0] == 'O')
                q.push({i,0});
            if(board[i][col-1] == 'O')
                q.push({i,col-1});
        }
        for(int i = 0;i<col;i++){
            if(board[0][i] == 'O')
                q.push({0,i});
            if(board[row-1][i] == 'O')
                q.push({row-1,i});
        }
        //vector<vector<int>> visit(row,vector<int>(col,0));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            board[x][y] = 'A';
            q.pop();
            for(int d = 0;d<4;d++){
                int xi = x + dirs[d][0];
                int yi = y + dirs[d][1];
                if(xi >= 0 && xi < row && yi >= 0 && yi < col){
                    if(board[xi][yi] == 'O'){
                        board[xi][yi] = 'A';
                        q.push({xi,yi});
                    }
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
        return;
    }
};

// @lc code=end
