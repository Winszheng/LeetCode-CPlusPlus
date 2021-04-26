/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// 用滑动窗口滑一遍数组，妙啊
// 要注意细节...
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 初始的时候，滑动窗口里不应该有元素
        int l = 0, r = -1, sum = 0, re = nums.size()+1;
        while(l < nums.size()){ // 滑动窗口滑一次
            if( r+1 < nums.size() && sum<target)sum+=nums[++r];   // r有可能越界
            else sum-=nums[l++];

            if(sum >= target)re = min(re, r-l+1);
        }
        if(re == nums.size()+1)return 0;
        return re;
    }
};
// @lc code=end

