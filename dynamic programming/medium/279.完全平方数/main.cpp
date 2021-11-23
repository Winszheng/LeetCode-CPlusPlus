#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
// 求完全平方数 - 典型的划分型动态规划
// 1.状态：最后一步的上一步也是完全平方数
// f[i] 表组成i的平方数的最少数量
// 2，状态转移方程
// f[i] = min{f[i-j^2]} + 1 ==> j <= sqrt(i)    减少循环次数 不等式
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX); dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sqrt(i); j++){
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }
};