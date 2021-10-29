#include <vector>
using namespace std;

// 股票问题，本质上只要每天手里剩下的钱是最多的就行了
// 多次交易求最优，状态转移方程
// buy = max(buy, sell-p)
// sell = max(sell, buy+p)

// 之前还用单调栈去模拟收集每个上升段
// 方法不够直观 空间效率不够优秀

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MIN/2, sell=0;  
        for(int p:prices) {
            buy = max(buy, sell-p);
            sell = max(sell, buy+p);
        }
        return sell;
    }
};