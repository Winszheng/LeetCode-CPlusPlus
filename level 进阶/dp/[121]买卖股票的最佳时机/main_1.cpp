/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

// 到最后一天只有三种状态

// 可以过而且效率高
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy=INT_MIN, sell=0;
      for(int p: prices){
          buy = max(buy, -p);   // 过去成本 vs. 当前成本
          sell = max(sell, buy+p);  // 过于收益 vs. 当前收益 - 买了卖
      }
      return sell;
    }
};
// @lc code=end

