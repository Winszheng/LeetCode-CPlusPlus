#include <vector>
using namespace std;

// fx 表最后偷x的最优解
// fi = nums[i] + max{f0-f(i-2)}
// 最后返回fx fx-1 flag中的最大值

// 法1：
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size() == 1)return nums[0];
//         if(nums.size() == 2)return max(nums[0], nums[1]);
//         int n = nums.size(); vector<int> dp(n);
//         dp[0] = nums[0], dp[1] = nums[1];
//         int pre = nums[0];  // 0到i-2上能拿到的最优解
//         for(int i=2; i<n; i++){
//             dp[i] = nums[i] + pre;
//             pre = max(pre, dp[i-1]);
//         }
//         return max(pre, dp[n-1]);
//     }
// };

// 法2 思路都是一样的，没什么改写必要
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        int n = nums.size();
        int pre = nums[0], before = nums[1], cur;
        for(int i=2; i<n; i++){
            cur = nums[i] + pre;
            pre = max(pre, before);
            before = cur;
        }
        return max(pre, cur);
    }
};