/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
// 优化做法：三指针，只需要对数据做一次循环
// 定义循环不变量
// zero：指向0序列最后一个元素
// one：指向当前处理的元素
// two：指向2序列的最先一个元素
// 当one == two时，说明这个元素肯定是2，不需要处理
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero = -1, one = 0, two = nums.size();
       while(one < two){
           if(nums[one] == 0){
               zero++;
               swap(nums[zero], nums[one]);
               one++;
           }else if(nums[one] == 2){
               two--;
               swap(nums[one], nums[two]);
           }else one++;
       }
    }
};
// @lc code=end

