/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start

// 思路和其他回溯题一样
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 91.58 % of cpp submissions (6.2 MB)

class Solution {
    void resolve(vector<vector<int>>& re, vector<int>& temp, int target, int k, int start){
        if(target < 0)return;
        if(target == 0 && temp.size() == k){
            re.push_back(temp);
            return;
        }

        for(int i = start; i < 10; i++){
            temp.push_back(i);
            resolve(re, temp, target - i, k, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> re;
        vector<int> temp;
        resolve(re, temp, n, k, 1);
        return re;
    }
};
// @lc code=end

