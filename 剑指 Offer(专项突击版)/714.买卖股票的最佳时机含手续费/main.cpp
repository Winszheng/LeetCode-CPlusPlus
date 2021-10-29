#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// 无限交易次数，只是要付手续费
// 本质要保证-每天结束，手里的钱是最多的
// define buy: 今天结束后，买入的最优利润
// define sell: 今天结束后，买入的最优利润
// 只是多了一个扣钱步骤，其他都是一样的
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN, sell=0;
        for(int p : prices){
            buy = max(buy, sell-p-fee);
            sell = max(sell, buy+p);
        }
        return sell;
    }
};

int main() {
    vector<int> p{1, 3, 2, 8, 4, 9};
    Solution s;
    cout<<s.maxProfit(p, 2)<<endl;
}