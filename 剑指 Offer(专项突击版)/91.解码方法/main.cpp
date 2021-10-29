#include <string>
#include <vector>
using namespace std;
// 求解码方式的总数 —— 典型的单序列动态规划
// 1.define dp[i] : 从0~i能拿到的所有结果
// 2.状态转移方程
//  dp[i] = dp[i-1] + dp[i-2]
//  对于dp[i-2], 需要对字符合法性进行判断

// 0开头，非法; 0在其他地方，减少一种可能
// 没有大片连续的0
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] != '0')dp[i] += dp[i-1];
            string t = s.substr(i-1, 2);
            int tmp = stoi(t);
            if(tmp > 9 && tmp < 27){
                if(i-2>=0)dp[i] += dp[i-2];
                else dp[i] += 1;
            }
        }
        return dp[n-1];
    }
};

