/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
// 思路和283题移动零是一模一样的
// 返回的是新数组的长度
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int num = 0;
        for(int &x : nums){
            if(x != val){
                swap(x, nums[i]);
                i++;
            }else{
                num++;
            }
        }
        return nums.size() - num;
    }
};
// @lc code=end

