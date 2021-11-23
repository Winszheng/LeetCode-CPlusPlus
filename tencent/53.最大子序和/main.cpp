#include <vector>
using namespace std;

// 最大子序和：求连续子数组加和的最优解 典型的动态规划
// 1.定义f[i]表以i为结尾的最优解
// 2.对每个f[i], 如果f[i-1]>0，就可以加和，否则，置为nums[i]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), re=nums[0], pre=nums[0];
        for(int i=1; i<n; i++){
            if(pre < 0)pre = nums[i];
            else pre = nums[i] + pre;
            re = max(re, pre);
        }
        return re;
    }
};