/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
using namespace std;
// @lc code=start
// 思路：套多一重循环的双指针
// 和 15题.三数之和 的解决思路一模一样
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int ta1 = target-nums[i];
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int ta2 = ta1-nums[j];
                int l=j+1, r=n-1;
                while(l<r){
                    int t = nums[l]+nums[r];
                    if(t == ta2){
                        re.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while(l<n && nums[l]==nums[l-1])l++;
                    }else if(t < ta2)l++;
                    else r--;
                }
            }
        }
        return re;
    }
};
// @lc code=end

