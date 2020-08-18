/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
/*
2020-8-18 09:33:08
题目确实读着怪怪的

2020-8-18 09:48:23
dfs写完了

目前这种有个问题：image[sr][sc] 和newColor颜色相同的话，可能会产生无限的搜索，涂色操作无法作为“已搜索”的标记。

2020-8-18 09:55:34
fix bug
```cpp
Accepted

277/277 cases passed (16 ms)

Your runtime beats 67.35 % of cpp submissions

Your memory usage beats 90.38 % of cpp submissions (13.6 MB)
```

写一写bfs吧
2020-8-18 10:02:55
搞定了

```
Accepted

277/277 cases passed (12 ms)

Your runtime beats 90.97 % of cpp submissions

Your memory usage beats 77.84 % of cpp submissions (13.8 MB)
```

2020-8-18 10:07:34
加了个先判断再push的bfs，似乎并没什么区别。


*/

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    const int dr[4] = {1,0,0,-1};
    const int dc[4] = {0,1,-1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        // dfs(image, sr, sc, image[sr][sc], newColor);
        bfs(image, sr, sc, image[sr][sc], newColor);
        // bfs2(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (image.empty()) return;
        int rLen = image.size();
        int cLen = image[0].size();
        if (sr < 0 || sr >= rLen || sc < 0 || sc >= cLen || image[sr][sc] != oldColor) return;

        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, oldColor, newColor);
        dfs(image, sr+1, sc, oldColor, newColor);
        dfs(image, sr, sc-1, oldColor, newColor);
        dfs(image, sr, sc+1, oldColor, newColor);
        return;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (image.empty()) return;
        int rLen = image.size();
        int cLen = image[0].size();

        queue<pair<int, int>> q;

        q.push(pair(sr,sc));
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if (p.first < 0 || p.first >= rLen || p.second < 0 || p.second >= cLen || image[p.first][p.second] != oldColor){
                continue;
            }
            image[p.first][p.second] = newColor;
            q.emplace(p.first-1, p.second);
            q.emplace(p.first+1, p.second);
            q.emplace(p.first, p.second-1);
            q.emplace(p.first, p.second+1);
        }
    }
    void bfs2(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (image.empty()) return;
        int rLen = image.size();
        int cLen = image[0].size();

        queue<pair<int, int>> q;

        if (sr < 0 || sr >= rLen || sc < 0 || sc >= cLen || image[sr][sc] != oldColor) return;
        q.push(pair(sr,sc));
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)//4方向
            {
                int next_r = r + dr[i];
                int next_c = c + dc[i];
                if(next_r >= 0 && next_r < rLen && next_c >=0 && next_c < cLen && image[next_r][next_c] == oldColor)
                {
                    q.emplace(next_r,next_c);
                    image[next_r][next_c] = newColor;
                }
            }
        }
    }
};
// @lc code=end

