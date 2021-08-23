/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
using namespace std;
// @lc code=start
// 其实就是多加了一个条件，第一件和最后一件不能同时被光顾
// 问题转换成，求
// 0 - n-2
// 1 - n-1
// 两个区间的最优解
class Solution {
    int resolve(vector<int> nums){
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);

        vector<int> dp(n);
        dp[0]=nums[0], dp[1]=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        return max(resolve(vector<int>(nums.begin(), nums.end()-1)), resolve(vector<int>(nums.begin()+1, nums.end())));
    }
};
// @lc code=end

