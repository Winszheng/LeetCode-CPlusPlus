/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
using namespace std;
// @lc code=start


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, re = 0;
        for(int i=0; i<prices.size(); i++){
            re = max(re, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }        
        return re;
    }
};
// @lc code=end

