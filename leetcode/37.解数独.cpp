/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isFound;
    vector<char> nums;
    void solveSudoku(vector<vector<char>>& board) {
        this->isFound = false;
        for (char i = '1'; i <= '9'; i++){
            nums.push_back(i);
        }
        solveSudokuR(board, 0, 0);
    }

    bool solveSudokuR(vector<vector<char>>& board, int x, int y) {
        if (x > 8){ // BUG
            // print board
            return true ;
        }
        int nextX, nextY;
        if (y < 8){ // BUG
            nextX = x;
            nextY = y+1;
        } else {
            nextX = x+1;
            nextY = 0;
        }

        if(board[x][y] != '.'){
            // already be filled
            return solveSudokuR(board, nextX, nextY);
        }

        // // to be filled
        vector<char> validNums;
        set<char> occurNums;
        for (int i = 0; i < 9; i++){
            occurNums.insert(board[x][i]);
            occurNums.insert(board[i][y]);
        }
        {
            int blockX = x/3 *3; // BUG
            int blockY = y/3 *3;// BUG
            for (int i = blockX; i < blockX+3; i++){
                for (int j = blockY; j < blockY+3; j++){
                    occurNums.insert(board[i][j]);
                }
            }
        }
        for (auto c : this->nums){
            auto result = occurNums.find(c);
            if (result == occurNums.end()){
                validNums.push_back(c);  // BUG
            }
        }
        // // TODO get valid nums in [x][y]
        // // if None then return
        if (validNums.size() == 0){
            return false;
        }
        for (auto i : validNums){
            // TODO use i
            board[x][y] = i;
            if (solveSudokuR(board, nextX, nextY)){
                return true;
            }
            // TODO cancel i
            board[x][y] = '.';
        }

        return false;
    
    }
};
// @lc code=end

