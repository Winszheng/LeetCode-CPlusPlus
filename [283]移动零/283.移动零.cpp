/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
// 考的是双指针，维持一个0序列
// l表有效队列末尾
// r表当前处理元素

// 这道题思路挺巧妙
// 就是朴素的交换
// 空间复杂度是常数级别的
// 时间复杂度是O（n）
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int &x : nums){
            if(x){
                swap(x, nums[i]);
                i++;
            }
        }
    }
};
// @lc code=end

