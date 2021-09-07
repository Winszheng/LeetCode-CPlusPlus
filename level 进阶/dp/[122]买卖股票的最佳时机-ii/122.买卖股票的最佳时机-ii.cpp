/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;
// @lc code=start

// 初始想法是单调栈
// 实际上不需要这么复杂，只要记录每一“段”的差值即可

// 某种程度上算脑筋急转弯
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

