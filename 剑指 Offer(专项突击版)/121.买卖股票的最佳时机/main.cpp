// a : 不断记录已有的最小值
// b : 不断试探获取最大利润

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = prices[0], b = 0;
        for(int i=1; i<prices.size();i++){
            b = max(b, prices[i]-a);
            a = min(a, prices[i]);
        }
        return b;
    }
};