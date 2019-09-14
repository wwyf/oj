/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.78%)
 * Likes:    3124
 * Dislikes: 109
 * Total Accepted:    421.1K
 * Total Submissions: 984.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * * Output: 3
 * 
 */
/*
很简单的深搜吧，深搜填一下格子就好。
*/
/*
√ Accepted
  √ 47/47 cases passed (12 ms)
  √ Your runtime beats 91.93 % of cpp submissions
  √ Your memory usage beats 43.82 % of cpp submissions (11 MB)
*/
class Solution {
public:
    int hlen;
    int wlen;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()){
            return 0;
        }
        wlen = grid[0].size();
        hlen = grid.size();
        vector <vector <int>> label(hlen,vector <int>(wlen)); 
        int ans = 0;
        for (int i = 0; i < hlen; i++){
            for (int j = 0; j < wlen; j++){
                if (label[i][j] != 1 && grid[i][j] == '1'){
                    visit(grid, label, j,i);
                    ans ++;
                }
            }
        }
        return ans;
        
    }
    // 通过深搜，将这个块的格子都走一遍。
    void visit(vector<vector<char> > & grid, vector<vector<int>> & label, int w, int h){
        label[h][w] = 1;
        int moves[4][2] = { {1, 0}, {-1, 0}, {0,1}, {0,-1}};
        for (int i = 0; i < 4; i++){
            int new_h = h + moves[i][0];
            int new_w = w + moves[i][1];
            if (0 <= new_h && new_h < hlen && 0 <= new_w && new_w < wlen && grid[new_h][new_w] == '1' && label[new_h][new_w] != 1){
                visit(grid, label, new_w, new_h);
            }
        }
    }
};

