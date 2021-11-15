#include <vector>
#include <limits.h>
using namespace std;

// 思路：
// 最多k次买卖求最优利润
// 本质是在维护k个买入状态+k个卖出状态
// 特殊点： 如果同一天买入卖出，实际上相当于零操作, 零操作不需要额外设置状态; 利润0就是保底

// b[i] : 表第i次买入状态 最优利润
// s[i] : 表第i次卖出状态 最优利润

// 状态转移方程
// b[i] = max(bi, s[i-1] - p[i]) 
// s[i] = max(s[i], b[i] + p[i])

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> b(k+1, INT_MIN), s(k+1, 0);      
        for(int p : prices){
            for(int i=1; i<k+1; i++){
                b[i] = max(b[i], s[i-1] - p);
                s[i] = max(s[i], b[i] + p); // 不小心写错
            }
        }
        int re = 0;
        for(int i=1; i<k+1; i++)re = max(re, s[i]);
        return re;
    }
};