#include <vector>
using namespace std;
// 最多k次交易求最优
// 实际上每天结束后有2k个状态(不交易不用考虑)
// 那么维护2k个状态每天能拿到的最优解就可以
// 为了方便计算，增加一个假状态
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> b(k+1, INT_MIN), s(k+1, 0);
        for(int p : prices){
            for(int i=1;i<=k;i++){
                b[i] = max(b[i], s[i-1]-p);
                s[i] = max(s[i], b[i]+p);   // 不小心写错
            }
        }
        sort(s.begin(), s.end());
        return s[k];
    }
};