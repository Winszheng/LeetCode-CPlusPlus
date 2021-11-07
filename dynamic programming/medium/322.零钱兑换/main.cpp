#include <vector>
#include <limits.h>
using namespace std;

// 零钱兑换 - medium

// 1.定义状态 fx : 凑成x的最少硬币数
// 2.定义状态转移方程 fx = min{f(x-ak)} + 1 在通过之前所有最优解产生当前最优解

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i <= amount; i++){
            for(int n : coins){ // 对每个金额，逐个试一遍
                if(i-n>=0 && dp[i-n] != INT_MAX)dp[i] = min(dp[i], dp[i-n]+1);
            }
        }
        return dp[amount]==INT_MAX ? -1: dp[amount];
    }
};