/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 95.1 % of cpp submissions (5.7 MB)

// 上楼梯这个题，本质上和斐波那契是一样的
// 靠递归会超时，所以选择了记录中间结果的方式
// 树状的、动态规划的结构
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)return 1;
        if(n == 2)return 2;
        int a = 1, b = 2, t;
        for(int i = 2; i < n; i++){
            t = a; a = b; b = a + t;
        }
        return b;
    }
};
// @lc code=end

