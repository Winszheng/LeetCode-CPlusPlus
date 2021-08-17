/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
// 问题可以转换为，在算数式添加+1、-1、0系数，求当结果为0时，正数的最大和
// define dp[i]表当结果为i时，能获取的最大正数和
// 全负-sum，和sum，所以下标范围是2sum+1，每个结果加sum使用，最后返回sum下标对应的结果
// 对每条钢筋，有左、右、弃权，三种操作，弃权相当于空操作
// 用map比较好写
// 对每条钢筋，遍历上一步获取的所有映射值，进行加减操作, 这样返回的是key为0时的值。
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
       unordered_map<int, int> dp; dp[0] = 0;   // 有无设置初始值，差别很大
       for(int r : rods){
           unordered_map<int, int> temp(dp);
           for(auto m : temp){
               int sum = m.first, num = m.second;
               dp[sum+r] = max(dp[sum+r], num+r);
               dp[sum-r] = max(dp[sum-r], num); // 减法时，正数和没有改变
           }
       }
       return dp[0];
    }
};
