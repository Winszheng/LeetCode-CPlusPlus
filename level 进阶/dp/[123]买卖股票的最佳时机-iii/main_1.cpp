/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
using namespace std;
// @lc code=start

// 只能做两次交易，每天只有5中情况
// 1.没有买入卖出-不用考虑
// 2.买1次、卖0次
// 3.买1次、卖1次
// 4.买2次、卖1次
// 5.买2次、卖2次

// 注意同一天买入卖出等于0操作

// 参考leetcode.动态规划精讲
class Solution {
public:
    int maxProfit(vector<int>& prices) {          
        int buy1=-prices[0], sell1=0;
        int buy2=-prices[0], sell2=0;
        for(int i=1;i<prices.size();i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);  // 第二次买入的最优成本
            sell2 = max(sell2, buy2+prices[i]);
        }
        // 因为状态转移和边界维护，所以只返回sell2即可
        return sell2;
    }
};
// @lc code=end

