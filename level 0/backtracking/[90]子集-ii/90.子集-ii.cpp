/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
// 返回带重复元素数组的所有子集，子集不能重复
// 去重思路和之前做的一样，排序+同一个进程中，重复的元素同事间处理

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 为啥会重复算了一次？
class Solution {
    void resolve(vector<vector<int>> &re, vector<int>& temp, vector<int>& nums, int k, int start){
        if(temp.size() == k){
            re.push_back(temp);return;
        }
        for(int i = start; i < nums.size(); i++){
            int j = i;
            while(j+1 < nums.size() && nums[j+1] == nums[j])j++;
            int index = 1, ii;
            while(i <= j){
                for(ii = 0; ii < index; ii++)temp.push_back(nums[j]);
                resolve(re, temp, nums, k, j+1);
                i++, index++;
                for(; ii > 0; ii--)temp.pop_back();
            }
            i--;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        re.push_back({});
        re.push_back(nums);
        for(int k = 1; k < nums.size(); k++){
            resolve(re, temp, nums, k, 0);
        }
        return re;
    }
};
// @lc code=end

