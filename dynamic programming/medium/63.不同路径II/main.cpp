#include <vector>
using namespace std;
// 也是典型的二维dp
// 1.定义状态f(x, y)表走到(x,y)的方法数，最后一步只能往下or往右走
    // 因此，答案来源于左侧和上方的子问题，是它们的加和
// 2.状态转移方程
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i>0)dp[i][j] += dp[i-1][j];
                if(j>0)dp[i][j] += dp[i][j-1];
                if(obstacleGrid[i][j])dp[i][j] = 0;
            }
        }
        return dp[n-1][m-1];
    }
};