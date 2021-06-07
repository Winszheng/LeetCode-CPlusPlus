/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// 初始思路:递归, 36/116超时
// 有很多重复的栈
class Solution {
    bool resolve(vector<int>& nums, int mid, int index){
        if(mid == 0)return true;
        if(mid < 0 || index < 0)return false;
        return resolve(nums, mid, index-1) || 
        resolve(nums, mid - nums[index], index-1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)sum+=n;
        if(sum % 2 == 1)return false;
        int mid = sum/2;

        return resolve(nums, mid, nums.size()-1);
    }
};
// @lc code=end

