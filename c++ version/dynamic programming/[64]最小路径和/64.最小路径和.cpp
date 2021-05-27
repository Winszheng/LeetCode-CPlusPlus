/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
// 最小路径和，求从左上角到右下角最小路径的和，注意，每次只能向右或者向下走
// Your runtime beats 99.37 % of cpp submissions
// Your memory usage beats 95.64 % of cpp submissions (9.3 MB)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();
       for(int i = 1; i < n; i++){
           grid[i][0] = grid[i][0] + grid[i-1][0];
       }
       for(int j = 1; j<m;j++){
           grid[0][j] = grid[0][j] + grid[0][j-1]; 
       }
       for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
               grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
           }
       }
       return grid[n-1][m-1];
    }
};

// @lc code=end

