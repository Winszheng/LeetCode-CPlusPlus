#include <vector>
using namespace std;
// 典型的 动态规划- 单序列问题
// 1.dp[i] : 从0-i能获取的最优解
// 2.那么有状态转移方程：
// dp[i] = max(dp[i-1], dp[i-2] + nums[i])
// 不断地求子结构的最优解
// 其实仅仅是三个变量之间的状态转移
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        int a = nums[0], b = max(nums[0], nums[1]), c;
        for(int i=2; i<n; i++){
            c = max(b, a+nums[i]);
            a = b, b = c;
        }
        return c;
    }
};