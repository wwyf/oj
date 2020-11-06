/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        int ns[3][9][9];
        memset(ns, 0, sizeof(int)*3*9*9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int bn =  (i/3)*3 + j/3;
                int num = board[i][j]-'1';
                if (ns[0][i][num] != 0 || ns[1][j][num] != 0 || ns[2][bn][num] != 0){
                    return false;
                }
                ns[0][i][num] = 1;
                ns[1][j][num] = 1;
                ns[2][bn][num] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

