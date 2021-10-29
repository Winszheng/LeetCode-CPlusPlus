#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
// 找到最少的完全平方数，使之和为n
// define dp[n]表n的最优拆解结果
// 对每个n，if存在t*t == n, dp[n] = 1
// else 
// dp[n] = INT_MAX
// 然后用平方数不断迫近结果

// 坑：sqrt返回的是double，要强制转换成int
class Solution {
public:
    int numSquares(int n) {
        if(n < 4)return n;
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 1;
        for(int i=5; i<=n; i++){
            int t = sqrt(i);
            if(t*t == i){
                dp[i] = 1;
                continue;
            }
            dp[i] = INT_MAX;
            for(int j=1; j*j < i; j++){
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }
        return dp[n];

    }
};

int main(){
    Solution s;
    s.numSquares(12);
}