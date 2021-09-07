/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;
// @lc code=start

// 因为可以进行多次交易，所以本质上要存储所有增长点
// 这样更直观
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int re=0, n=prices.size();
       for(int i=1;i<n;i++){
           if(prices[i]>prices[i-1])re += prices[i]-prices[i-1];
       }
       return re;
    }
};
// @lc code=end

