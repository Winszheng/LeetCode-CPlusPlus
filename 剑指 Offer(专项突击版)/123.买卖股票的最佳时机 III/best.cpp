#include <vector>
using namespace std;


// 最多两次交易，求最优利润
// 每天结束后需要考虑的有四种状态
// 一次买入、一次卖出
// 二次买入、二次卖出
// (不交易状态不需要考虑)
// 只要求每天结束后，这四个状态的最优利润即可

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MIN, b2=INT_MIN, s1=0, s2=0;
        for(int p : prices){
            b1 = max(b1, -p);
            s1 = max(s1, b1+p);
            b2 = max(b2, s1-p); // 之前买入的最有利润 vs. 当前探测的最优利润
            s2 = max(s2, b2+p);
        }
        return max(s1, s2);
    }
};