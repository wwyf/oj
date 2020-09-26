/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool visited[201][201];
    int dirs[4][2];
    int x_length;
    int y_length;
    bool exist(vector<vector<char>>& board, string word) {
        memset(visited, 0, sizeof(bool)*201*201);
        dirs[0][0] = 0;
        dirs[0][1] = -1;
        dirs[1][0] = 0;
        dirs[1][1] = 1;
        dirs[2][0] = 1;
        dirs[2][1] = 0;
        dirs[3][0] = -1;
        dirs[3][1] = 0;
        x_length = board.size();
        if (x_length == 0){
            return false;
        }
        y_length = board[0].size();
        if (y_length == 0){
            return false;
        }
        for (int i = 0; i < x_length; i++){
            for (int j = 0; j < y_length; j++){
                auto ans = dfs(board, i, j, word, 0);
                if (ans){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, int x, int y, string word, int index){
        if (word[index] != board[x][y]){
            return false;
        }
        if (index == word.size()-1){
            return true;
        }
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++){
            int next_x = x + dirs[i][0];
            int next_y = y + dirs[i][1];
            if (0 <= next_x && next_x < x_length && 0 <= next_y && next_y < y_length){
                if (visited[next_x][next_y] == 0){
                    auto ans = dfs(board, next_x, next_y, word, index+1);
                    if (ans){
                        return ans;
                    }
                }
            }
        }
        visited[x][y] = 0;
        return false;
    }
};
// @lc code=end

