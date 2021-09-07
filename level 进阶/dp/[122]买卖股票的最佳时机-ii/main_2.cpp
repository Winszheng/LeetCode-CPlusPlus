/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;
// @lc code=start

// 可以把股票交易简化成 - 卖了买、买了卖的过程
// 基于这种思路，不断获取买入的最优成本、卖出的最优利润
// 过程中，所有利润状态最终都会转入最终状态，所以直接返回最终状态即可
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MIN/2, sell=0;
        for(int p : prices){
            buy = max(buy, sell-p);
            sell = max(sell, buy+p);
        }
        return sell;
    }
};
// @lc code=end

