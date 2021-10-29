/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
// 本质上和三数之和是一样的，只是需要比较获取最佳结果
// 报错；
// cannot be represented in type 'int'
// 原因：re = INT_MAX，是最大的整数，当target是负数的时候，就溢出了
// 当使用INT_MAX的时候，如果需要做减法运算，需要保证进来的不是负数
// 为了避免这个问题，直接用是否等于去做判断

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), re = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(re == INT_MAX)re = sum;  
                else if(abs(re-target) > abs(sum-target))re = sum;
                else if(sum < target)l++;
                else r--;
            }
        }
        return re;
    }
};
// @lc code=end

