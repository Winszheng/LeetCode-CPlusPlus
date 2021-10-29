/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
using namespace std;

// 思路不难，细节不少
// 最终用了两重循环，没想到效率就已经不错了
class Solution {
public:
// 形参是个引用
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> re{};
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            if(nums[i] > 0)break;
            if(i>0 && nums[i]==nums[i-1])continue;  // 相同的元素，本质上用谁都一样，所以可以直接跳过

            int target = 0-nums[i];
            int l = i+1, r=n-1;
            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    re.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while(l<r && nums[l] == nums[l-1])l++;
                    while(l<r && nums[r] == nums[r+1])r--;
                }
                else if(sum < target)l++;
                else r--;
            }
        }
        return re;
    }
};
// @lc code=end

