/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// 定义d[i]表第i天能获取的最大利润, 不断记录最低股票价格与最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfile=0, minPrice=prices[0], n=prices.size();
        for(int i=1;i<n;i++){
            maxProfile = max(maxProfile, prices[i]-minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        return maxProfile;
    }
};
// @lc code=end

