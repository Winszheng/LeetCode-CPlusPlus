/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
// 虽然思路有点奇怪，但是确实是O(n)
// 优化方向：只做一次循环
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};  // c++缺省初始化后会自动补零
        for(int x : nums){
            count[x]++;
        }
        int i;
        for(i=0;i<count[0];i++)nums[i]=0;
        for(;i<count[0]+count[1];i++)nums[i]=1;
        for(;i<count[0]+count[1]+count[2];i++)nums[i]=2;
    }
};
// @lc code=end

