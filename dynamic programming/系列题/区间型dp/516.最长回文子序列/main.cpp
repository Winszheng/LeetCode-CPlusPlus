#include <string>
#include <vector>
using namespace std;
// 求字符串的最长回文子序列
// 显然是个dp，而且是区间型dp
// 1.定义状态f[i][j]表示下标[i,j]之间的最长回文子序列长度
// 2.状态转移方程
// f[i][j] = max{f[i][j-1], f[i+1][j], f[i+1][j-1] + 2 | s[i]==s[j]}
// 3.初始化，长度为1、长度为2的需要特殊操作

// 思路确实是这个思路，内存消耗还行，但是时间消耗很不理想
// 优化思路：
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp初始化，不管你取了怎样的区间，最差的结果也是1
        vector<vector<int>> dp(n, vector<int>(n, 1));   
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = s[i]==s[i+1] ? 2 : 1;
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                if(s[i] == s[i+len-1])dp[i][i+len-1] = max(dp[i][i+len-1], dp[i+1][i+len-2]+2);
                else dp[i][i+len-1] = max(dp[i][i+len-2], dp[i+1][i+len-1]);
            }
        }
        return dp[0][n-1];
    }
};