/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

// 组合总和
// 如何解决元素可以重复这件事？排序+传进去的下标不加一即可
// start本质作用：逐步缩小组合能用的范围 
class Solution {
    void resolve(vector<vector<int>>& re, vector<int>& temp, int target, vector<int>& candidates, int start){
        if(target == 0){
            re.push_back(temp);
            return;
        }
        if(target < 0)return;
        for(int i = start; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            resolve(re, temp, target - candidates[i], candidates, i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        resolve(re, temp, target, candidates, 0);
        return re;
    }
};
// @lc code=end

