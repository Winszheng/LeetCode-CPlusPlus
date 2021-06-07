/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// 典型的背包问题，只是没有权值，也没有余量
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);  // 求和
        if(sum % 2 == 1)return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);  // dp[i]表是否可以通过选取元素得到权值i
        dp[0] = true;       // 不选取任何元素时，权值为0
        for(int n : nums){
            for(int i = sum; i >= n; i--){
                dp[i] = dp[i] || dp[i - n];
                // cout<<dp[i]<<" ";
            }
            // cout<<endl;
        }

        return dp[sum];
    }
};

// int main(){
//     Solution s;
//     vector<int> sum{1, 3, 8, 5, 11};
//     s.canPartition(sum);
// }
// @lc code=end

