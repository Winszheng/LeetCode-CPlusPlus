/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

// 典型dp题，关键是找到状态转移方程
// define: d[i]表[0~i]能得到的最优结果
// init: d[0] = nums[0], d[1] = max(nums[0], nums[1]), d[2] = max(nums[2] + d[0], d[1])
// so if i > 1, d[i] = max(d[i-2]+nums[i], d[i-1])

// 简化一下，只要用3个变量存d[i-2], d[i-1], d[i]即可

// 比较：
// 1.两种方法速度都是100%
// 2.方法1空间效率50%+， 方法2 90%+
// 不过我觉得本质思路是一样的，第一种可读性更强，比较好

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), temp;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        // vector<int> dp(n, 0);
        int a = nums[0], b = max(nums[0], nums[1]), c = 0;
        for(int i = 2; i < n; i++){
            c = max(b, nums[i]+a);
            a = b, b = c;
        }
        return c;
    }
};
// @lc code=end

