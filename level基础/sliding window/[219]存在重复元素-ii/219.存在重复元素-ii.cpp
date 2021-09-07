/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
// 初始做法：滑动窗口+双指针——不省事

// 改进做法：固定长度的滑动窗口
// 用一个“固定”大小的set来表征这个滑动窗口
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> temp;
        for(int i=0;i<nums.size();i++){
            if(temp.find(nums[i]) != temp.end())return true;    // found
            temp.insert(nums[i]);
            if(temp.size() == k+1)temp.erase(nums[i-k]);
        }
        return false;
    }
};
// @lc code=end

