/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
// 一遍ace
// 双指针真好用
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, w, h, v = 0;
        while(l<r){
            w = r-l;
            h = min(height[l], height[r]);
            v = max(v, w*h);
            if(height[l] > height[r])r--;
            else l++;
        }
        return v;
    }
};
// @lc code=end

