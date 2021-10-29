#include <vector>
using namespace std;
// 典型的 动态规划 - 矩阵路径问题
// dp[i][j] : 表从左上角到(i,j)能拿到的所有路径
// 那么，对每一个dp[i][j],可以找到这样的状态转移方程
// 每一个格子的结果只能来源于左和上
// dp[i][j] = dp[i-1][j] + d[i][j-1]
// 第一行和第一列可以直接初始化

// 时间效率很高，空间效率有点低
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0;i<m;i++)dp[i][0] = 1;
        for(int i=0;i<n;i++)dp[0][i] = 1;
        for(int i=1; i<m; i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};