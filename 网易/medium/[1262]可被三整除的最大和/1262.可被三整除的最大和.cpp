/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */
#include <algorithm>
using namespace std;
// @lc code=start

// 典型的背包问题，dp解决
// define dp[i]表余数为i时的最大和，此时只要考虑0、1、2即可
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int re[3] = {0};
        for(auto n : nums){
            int a, b, c;
            a = re[0] + n;
            b = re[1] + n;
            c = re[2] + n;
            re[a%3] = max(re[a%3], a);
            re[b%3] = max(re[b%3], b);
            re[c%3] = max(re[c%3], c);
        }
        return re[0];
    }
};
// @lc code=end

