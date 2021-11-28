#include <vector>
#include <iostream>
using namespace std;
// 4个物品，重量 2, 3, 5, 7
// 背包承重 11
// 问：背包最多能放多重的东西？

// 思路，探索组成0-M的所有可能性即可
// 这个做法肯定不对，不仅不对，而且含糊
// 怎么办呢？
class Solution{
public:
    int bags(vector<int> &nums, int m) {
        vector<bool> dp(m+1, false); dp[0] = true;
        for(int n : nums) {
            if(n <= m) dp[n] = true;
            for(int i=n+1; i+n<=m; i++){
                if(dp[i])dp[i+n] = true;    
            }
        }
        
        for(int i=m; i>0; i--){
            if(dp[i])return i;
        }
        return -1;
    }
};

int main(){
    vector<int> test1{2, 3, 5, 7};
    Solution s;
    cout<<s.bags(test1, 11)<<endl;
}