#include <vector>
using namespace std;

// 真是离谱，为啥我会接受不了
// 定义dp[i]表0-i上能拿到的最优解
// dp[i] = max(dp[i-1], dp[i-2]+nums[i])
// 实际上一直在进行三个变量（两个也行）的状态转移
// 但是三个写着省事
class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n == 1)return nums[0];
       if(n == 2)return max(nums[0], nums[1]);
       int a = nums[0], b=max(nums[0], nums[1]), c;
       for(int i=2; i<n; i++){
           c = max(b, a+nums[i]);
           a = b, b = c;
       }
       return c;
    }
};