/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
using namespace std;
// @lc code=start

// 最多进行两次交易，获取最优值
// INT_MIN/2 是为了避免减法运算带来的溢出
// 只返回se2，是因为所有卖出状态在循环中强制转换到了最终
class Solution {
public:
    int maxProfit(vector<int>& prices) {          
       int buy1=INT_MIN/2, buy2=INT_MIN/2, se1=0, se2=0;
       for(int p:prices){
           buy1 = max(buy1, -p);    // 要么以前买过，要么现在才买
           se1 = max(se1, buy1+p);  // 以前卖过 or 买了卖
           buy2 = max(buy2, se1-p); // 以前买过 or 卖了买
           se2 = max(se2, buy2+p);  // 以前卖过 or 买了卖
       }
       return se2;
    }
};
// @lc code=end

