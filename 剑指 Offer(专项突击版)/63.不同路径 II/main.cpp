#include <vector>
using namespace std;
// 思路不变，每个格子的结果只能来源于左或者上
// 但是多了障碍物来影响判断
// 障碍物真正的意思应该是，无法接收来自左侧和上方的结果，也就是应该直接置为0

// 左上角也可以放障碍！！！

// 时间效率100%，空间效率低，要想提高空间效率，在原数组上改
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        for(int i=1;i<m;i++){
            dp[0][i] = obstacleGrid[0][i]==1 ? 0 : dp[0][i-1]; 
        }
        for(int i=1;i<n;i++){
            dp[i][0] = obstacleGrid[i][0]==1 ? 0 : dp[i-1][0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = obstacleGrid[i][j]==1 ? 0 : dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};