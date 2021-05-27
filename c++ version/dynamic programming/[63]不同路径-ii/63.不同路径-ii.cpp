/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
// 和63题的思路是一样的，因为多了障碍，所以需要分类讨论
// 1.初始化左边界、上边界的时候，如果遇到阻碍，后面的就到不了，即为0
// 2.对于障碍，直接跳过，否则会因为改变了障碍的值做错
// 3.如果入口或出口是障碍，直接无解

// 下面的代码存在冗余，但是我觉得不必计较
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1)obstacleGrid[i][j] = -1;
            }
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0] == -1)break;
            else obstacleGrid[i][0] = 1;
        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i] == -1)break;
            else obstacleGrid[0][i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j] == -1)continue;
                if(obstacleGrid[i][j-1] != -1)obstacleGrid[i][j] += obstacleGrid[i][j-1];
                if(obstacleGrid[i-1][j] != -1)obstacleGrid[i][j] += obstacleGrid[i-1][j];
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};
// @lc code=end

