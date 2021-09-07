/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <vector>
using namespace std;
// @lc code=start
// 不断获取第i次交易，买入卖出的最优解，迭代获取最值
// 最多完成k次交易

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // buy_i sell_i
        vector<vector<int>> d(k+1, vector<int>(2));

        // 买入价要先设置成一个很大的值
        for(int i=0;i<k+1;i++)d[i][0] = INT_MIN/2;
        // 对每一个报价，迭代求当前最优解
        for(int p : prices){   
            // 不断迭代求k次交易能拿到的最优解
            for(int j=1;j<k+1;j++){
                d[j][0]=max(d[j][0], d[j-1][1]-p);  // 卖了买
                d[j][1]=max(d[j][1], d[j][0]+p);   // 买了卖
            }
        }
        return d[k][1];
    }
};
// @lc code=end

