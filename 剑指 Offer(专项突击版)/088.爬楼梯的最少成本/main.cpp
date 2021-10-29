#include <vector>
#include <iostream>
using namespace std;

// 这道题的语文水平好差==
// 题目实际要做的是： 求离开每一层阶梯所要付出的代价， 并返回最后两个代价中，比较小的那个

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n); dp[0]=cost[0], dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};

int main(){
    Solution s;
    vector<int> temp1{10, 15, 20};
    vector<int> temp2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<s.minCostClimbingStairs(temp1)<<endl;
    cout<<s.minCostClimbingStairs(temp2)<<endl;
}