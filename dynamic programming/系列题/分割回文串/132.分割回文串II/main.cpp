#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
// 求：回文串的最少分割次数
// 1.定义状态f[i]表到i为止的最少分割次数
// 2.状态转移方程
// f[i] = min{f[j] | [j,i] is palinedrome} + 1
// 因为状态转移方程不是简单的比大小，多了一层判断是否回文，因此是三重循环
// 可以按区间长度扩展遍历，把回文状态记忆化
// 相当于单序列遍历 +   区间遍历
// 内存和时间消耗都还行


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> mem(n, vector<bool>(n, true));
        // 1.区间dp构造回文串地图
        for(int len=2; len<=n; len++){
            for(int i=0, j=len-1; j<n; i++, j++){
                if(s[i]!=s[j] || !mem[i+1][j-1]){
                    mem[i][j] = false;
                }
            }
        }

        vector<int> dp(n, INT_MAX); dp[0] = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(mem[j][i]){   
                    if(j == 0)dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    cout<<s.minCut("aab")<<endl;
}

// 1.初始方法
// class Solution {
// public:
//     string s;
//     bool isp(int i, int j){
//         while(i < j){
//             if(s[i] != s[j])return false;
//             i++, j--;
//         }
//         return true;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n, INT_MAX); dp[0] = 0;
//         this->s = s;
//         for(int i=1; i<n; i++){
//             for(int j=0; j<=i; j++){
//                 if(isp(j, i)){   // 方法2是把这层循环抽出来变成平行的，从而省略一层复杂度
//                     if(j == 0)dp[i] = 0;
//                     else dp[i] = min(dp[i], dp[j-1] + 1);
//                 }
//             }
//         }
//         return dp[n-1];
//     }
// };
