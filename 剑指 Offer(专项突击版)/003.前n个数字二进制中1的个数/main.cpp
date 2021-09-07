// 求二进制数中1的个数
// key： i & (i-1) 能把i最右边的1变成0
// 那么这道题其实是dp的思路
// dp[0]=0
// i>1
// dp[i] = dp[i & (i-1)] + 1
// i中1的个数=比i少1个1的数的 1的个数 + 1

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re(n+1);
        for(int i=1;i<=n;i++){
            re[i] = re[i & (i-1)] + 1;
        }
        return re;
    }
};

// 我可要加油啊....!!