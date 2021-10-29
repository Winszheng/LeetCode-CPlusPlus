#include <vector>
using namespace std;

// 困难题：买卖股票-限制k笔交易
// 本质上是限制两笔交易的扩展
// 每天结束之后，有2k+1种状态，即第1~第k次买入、第1~第k次卖出、空操作
// 记录每种状态的最优解(最大利润)、同一天买入卖出等于空操作

// 一遍过
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 1.定义买入最优利润、卖出最优利润
        // 为了方便操作，补上第0次买入、卖出的状态
        vector<int> a(k+1, INT_MIN), b(k+1, 0); 
        for(int p : prices){
            for(int i=1;i<=k;i++){
                // 第i次买入的最优利润 = max(原结果, 第i-1次卖出获取的最大利润 - p)
                a[i] = max(a[i], b[i-1] - p);
                // 第i次卖出的最优利润 = max(原结果, 第i次买入 + p)
                b[i] = max(b[i], a[i] + p);
            }
        }
        sort(b.begin(), b.end());
        return b[k];
    }
};