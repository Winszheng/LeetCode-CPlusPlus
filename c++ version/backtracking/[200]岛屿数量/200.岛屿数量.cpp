/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// floodfill算法
// 每次登上一块岛屿，就用广搜，把搜过的地方置0
// 那么广搜过几次，就有几块岛屿

class Solution {
    int n, m;
    int loc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void resolve(vector<vector<char>>& b, int i, int j){    
        b[i][j] = 0;
        for(int ii = 0; ii < 4; ii++){
            int newi = i+loc[ii][0], newj = j+loc[ii][1];
            if(isValid(newi, newj) && b[newi][newj]=='1'){  // 边界问题
                resolve(b, newi, newj);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int re = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    re++;
                    resolve(grid, i, j);
                }
            }
        }
        return re;
    }
};
// @lc code=end

