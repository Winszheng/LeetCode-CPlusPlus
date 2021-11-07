#include <vector>
#include <limits.h>
using namespace std;

// 之前虾皮二面的题，凑出尽可能接近结果的金额
// define fx : 1表可以凑出这个结果，0表不能凑出
// fx : 对每个coin，查看上一任解是否存在，存在即可置1
// 最终返回倒序最接近amount的合法下标


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;  // amount为0默认能凑
        for(int i=1; i <= amount; i++){
            for(int n : coins){ // 对每个金额，逐个试一遍
                if(i-n>=0 && dp[i-n])dp[i] = 1;
            }
        }
        for(int i=amount; i>=0; i--){
            if(dp[i])return i;
        }
        return 0;
    }
};