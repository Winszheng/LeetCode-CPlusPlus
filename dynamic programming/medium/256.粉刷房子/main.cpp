#include <vector>
using namespace std;

// f[x][i] - 粉刷第x个房子时，选取i色能拿到的最小花费
// 时空效率还可以！

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size(); 
        vector<vector<int>> dp(n, vector<int>(m));
        // 还是直观写法比较方便
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(int i=1; i<n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
        }

        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
        
    }
};