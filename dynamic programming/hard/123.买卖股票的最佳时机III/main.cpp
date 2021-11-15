#include <vector>
using namespace std;

// 维护四个状态：第一次买卖、第二次买卖
// 状态转移方程, 对每个价格：
// b1 = max(b1, -p)
// s1 = max(s1, b1 + p)
// b2 = max(b2, s1 - p)
// s2 = max(s2, b2 + p)
// return max(b1, b2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN, b2 = INT_MIN, s1 = 0, s2 = 0;
        for(int p : prices){
            b1 = max(b1, -p);   // -p1
            s1 = max(s1, b1 + p);   // 0
            b2 = max(b2, s1 - p);   // -p1
            s2 = max(s2, b2 + p);   // 0
        }
        return max(s1, s2);
    }
};