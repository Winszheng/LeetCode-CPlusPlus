/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
// 官方题解讲得很简单
// 摆动序列，可以拆解成向上摆动序列，或向下摆动序列，序列中会有一些过度元素
// define down/up为向下摆动序列、向上摆动序列的长度
// 序列的结尾元素都是第i个元素
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int down = 1, up = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                up = max(up, down + 1);
            }else if(nums[i] < nums[i-1]){
                down = max(up+1, down);
            }
        }
        return max(up, down);
    }
};


// @lc code=end

