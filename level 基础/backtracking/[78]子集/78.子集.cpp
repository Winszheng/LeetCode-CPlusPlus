/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
// 子集——组合题，求一个集合的所有子集
// 思路和之前的题目是一样的
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 63.96 % of cpp submissions (6.9 MB)

class Solution {
    void resolve(vector<vector<int>>& re, vector<int>& temp, vector<int>& nums, int start, int k){
        if(temp.size() == k){
            re.push_back(temp);return;
        }
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            resolve(re,  temp, nums, i+1, k);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> temp;
        re.push_back({});
        re.push_back(nums);
        for(int k = 1; k < nums.size(); k++)resolve(re, temp, nums, 0, k);
        return re;
    }
};
// @lc code=end

