/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

// 思路和131是一样的，一遍过也没有爆内存，但是两个效率都很慢
// 本质上也是一道树形分叉题，根部空节点，每条到叶子的路上的权重和都是相同的
class Solution {
    void resolve(vector<vector<int>>& re, unordered_set<int> sett, vector<int> temp, int t){
        if( t != 11){
            sett.erase(t);
            temp.push_back(t);
            if(sett.empty()){
                re.push_back(temp);
                return;
            }
        }

        for(int i : sett){
            resolve(re, sett, temp, i);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> sett(nums.begin(), nums.end());
        vector<vector<int>> re;
        resolve(re, sett, {}, 11);
        return re;
    }
};
// @lc code=end

