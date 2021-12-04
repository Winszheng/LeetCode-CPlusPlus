#include <vector>
using namespace std;
// 博弈问题 先手必胜返回true
// 1.定义状态：计算总分并不现实，计算分差比较现实
// f[i][j]表示面对[i, j]范围的石子时，能与对方制造出的最大分差
// 那么，只要f[0][n-1]>0 则先手必胜
// 2.定义状态转移方程
// f[i][j] = max{p[i]-f[i+1][j], p[j]-f[i][j-1]}
// 3.初始化
// 只剩一个数字时，自己取得石子，对方零分
// f[i][i] = p[i]
// 只剩两个数字时，已经可以代入状态转移方程

// 能过，但是时空效率一般
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++)dp[i][i] = piles[i];
        for(int len=2; len<=n; len++){
            for(int i=0; i+len-1<n; i++)dp[i][i+len-1] = max(piles[i] - dp[i+1][i+len-1], piles[i+len-1] - dp[i][i+len-2]);
        }
        return dp[0][n-1] > 0;
    }
};