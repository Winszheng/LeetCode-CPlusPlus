#include <vector>
using namespace std;
// 1.定义状态 f(x, y)表(x, y)处的所有结果
// 2.定义状态转移方程
// 最后一步只能往下or往右走

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0)dp[i][j] += dp[i-1][j];
                if(j>0)dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};