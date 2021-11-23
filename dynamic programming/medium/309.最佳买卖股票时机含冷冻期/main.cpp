#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// 多次交易+含冷冻期 == 之前的四个题，仅仅考虑买入卖出 本质上没有把持有加入考虑因素
// 在此之前的4个股票题中，持有和不持有，实际上仅仅指买入和卖出
// 引入冷冻期的本质意思：第i个状态需要参考第i-2天的状态

// 1.定义状态
// b[i] 表第i天持有的最佳利润
// s[i] 表第i天不持有的最佳利润

// 2.状态转移方程
// 昨天就持有 今天买入才持有
// b[i] = max(b[i-1], s[i-2] - p)
// 昨天就不持有 今天卖出才不持有 
// s[i] = max(s[i-1], b[i-1] + p)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if(n == 1)return 0;
       if(n == 2)return max(0, prices[1]-prices[0]);
       vector<int> b(n, INT_MIN), s(n, 0);
       b[0] = -prices[0], b[1] = max(-prices[0], -prices[1]);
       s[1] = max(0, prices[1]-prices[0]);
       for(int i=2; i<n; i++){
           b[i] = max(b[i-1], s[i-2] - prices[i]);
           s[i] = max(b[i-1] + prices[i], s[i-1]);
       }
       return s[n-1];
    }
};

int main(){
    vector<int> test1{1,2,3,0,2};
    Solution s;
    cout<<s.maxProfit(test1)<<endl;
}