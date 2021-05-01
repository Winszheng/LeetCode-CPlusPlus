/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
using namespace std;
// 目标是用三重循环做完
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> re;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            // if(nums[i] > target)break; // 如果target是个负数，这是要积累的
            int a = target - nums[i];
            if(i>0 && nums[i]==nums[i-1])continue;  // 倒着确定元素
            for(int j = i+1; j<n-2; j++){
                int tar = a - nums[j];
                int l = j+1, r = n-1;
                if(j>i+1 && nums[j] == nums[j-1])continue;  // 
                while(l<r){
                    int sum = nums[l]+nums[r];
                    if(sum == tar){
                        re.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l<r && nums[l] == nums[l-1])l++;
                        while(l<r && nums[r] == nums[r+1])r--;
                    }else if(sum < tar)l++;
                    else r--;
                }
            }
        }
        return re;
    }
};
// @lc code=end

