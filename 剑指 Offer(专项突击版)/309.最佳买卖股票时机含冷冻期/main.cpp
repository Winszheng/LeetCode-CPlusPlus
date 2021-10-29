#include <vector>
#include <limits.h>
using namespace std;

// 题解：
// 不仅过了，而且时空效率是我目前写的最优的
// 1.股票题的本质，就是一天过去之后，手里的钱需要是最多的
// 买入的时候，手里的钱当然不是最多的，买入的定义实际是：
// buy[i] : 0-i的时间段中，买入能获得的最优解
// 卖出的定义：
// sell[i] : 0-i时间段中，卖出能获得的最优解
// 所以，实际上这是双因素的动态规划
// 2.所谓冷冻期，仅仅是限制了买入时间的合法性

// 多次交易含冷冻期
// 第i天结束后，只有这样几种状态
// 本日买入 a
// 本日卖出(或者也可以理解为冷冻期吧) b
// 本日没有买入卖出 c

// 那么就有状态转移方程
// a = max(a, -p)
// 说到底，这道题要求我，在每一天结束的时候，手里的钱都是最多的
// 那么，每一天接收，都有且仅有3个状态
// 今天买入(买入必须不在冷冻期)
// 今天卖出
// 零操作
// define dp[i] 表征两个状态: 买入 卖出
// 买入：昨天的买入最优利润 与今天的买入最有利润对比
// a[i] = max(a[i-1], b[i-2]-p)
// 卖出: 昨天的利润 与今天卖出的利润对比 
// b[i] = max(b[i-1], a[i-1]+p)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        vector<int> a(n, INT_MIN), b(n);
        a[0] = -prices[0], a[1] = max(-prices[0], -prices[1]);
        b[1] = max(0, prices[1]-prices[0]);
        for(int i=2;i<n;i++){
            a[i] = max(a[i-1], b[i-2]-prices[i]);
            b[i] = max(b[i-1], a[i-1]+prices[i]);
        }
        return b[n-1];
    }
};