#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// n个房子， k个色
// 要求O(nk)复杂度
// 对每一个当前状态，只要坐标和上一个状态的最小值不同，就直接加最小值；相同则加次小值
// 过程中不断计算当前状态的最小值、次小值与对应坐标

// 实际上利用的只是上一个状态的最小和次小，所以开一维空间的就够了
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k=costs[0].size();
        vector<int> dp(k);
        // 初始状态： 0状态的最小值、次小值、以及最小值对应下标
        int t1=0, t2=0, n1 = INT_MAX; 
        for(int i=0; i<n; i++){
            // 当前状态的最小、次小、最小值对应下标
            int tt1 = INT_MAX, tt2 = INT_MAX, nn2;
            for(int j=0; j<k; j++){
                dp[j] = costs[i][j];
                if(j == n1)dp[j] += t2;
                else dp[j] += t1;
                if(dp[j] < tt1){
                    tt2 = tt1;
                    tt1 = dp[j], nn2 = j;
                }else if(dp[j] < tt2)tt2 = dp[j];

            }
            t1 = tt1, t2 = tt2, n1 = nn2;
        }
        return t1;
    }
};

int main(){
    vector<vector<int>> test{{1,5,3}, {2,9,4}};
    Solution s;
    cout<<s.minCostII(test)<<endl;
}