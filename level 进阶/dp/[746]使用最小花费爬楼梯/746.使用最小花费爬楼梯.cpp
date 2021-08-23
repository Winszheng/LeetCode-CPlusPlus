/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;

// 字都是简体字，写在一起不知道题目要表达什么
// https://leetcode-cn.com/problems/min-cost-climbing-stairs/solution/746-shi-yong-zui-xiao-hua-fei-pa-lou-ti-8obj0/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2; i<n; i++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};
// @lc code=end

// 10 15 20
// 10 15 30
// min(15, 30)

