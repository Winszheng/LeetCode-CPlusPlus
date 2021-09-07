/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
// 相当于给无限次交易那道题多扣一个手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {   // 2
        int buy=INT_MIN, se=0;
        for(int p:prices){
            buy = max(buy, se-p);   // 卖了买
            se = max(se, buy+p-fee);//买了卖
        }
        return se;
    }
};
// @lc code=end

