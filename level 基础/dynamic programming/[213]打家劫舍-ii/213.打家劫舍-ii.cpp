/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

// 和198题一样，区别是房屋首尾相连
// 本质上相当于，不能同时选入首尾元素，那么如何规避这件事情？
// 做两次198题的dp，区别在于每次dp的范围：
// 0 ~ n-2
// 1 ~ n-1

// 可以拿迭代器初始化容器，但是犯了个错误；
// 形参写的引用，实参传的临时变量
// 这种“幽灵变量”当然不能当做引用
class Solution {
    int resolve(vector<int> nums){
        int n = nums.size();
        if(n == 2)return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        return max(resolve(vector<int>(nums.begin(), nums.end()-1)), resolve(vector<int>(nums.begin()+1, nums.end())));
    }
};
// @lc code=end

