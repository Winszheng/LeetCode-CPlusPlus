/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
using namespace std;
// @lc code=start
// 思路：二重循环 - 双指针
// 对遍历的每个元素, 寻找与之匹配的数字对，找到则加入结果
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> re;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int target = 0 - nums[i];
            int l = i+1, r = n-1;
            while(l<r){
                int t = nums[l]+nums[r];
                if(t == target){
                    re.push_back({-target, nums[l], nums[r]});
                    l++, r--;
                    while(l<n-1 && nums[l] == nums[l-1])l++;
                }else if(t < target)l++;
                else r--;
            }
        }
        return re;
    }
};
// @lc code=end

