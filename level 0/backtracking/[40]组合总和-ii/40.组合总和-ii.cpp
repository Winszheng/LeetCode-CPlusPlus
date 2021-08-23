/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
// 组合总和II
// 给定的每个元素在每个组合中只能使用一次，但是元素是有重复的，coder要避免出现重复的组合

// 解决方法，每次发现有重复元素，就把每种情况递归一遍，然后跳到下一个元素

// Your runtime beats 70.69 % of cpp submissions
// Your memory usage beats 95.21 % of cpp submissions (10.2 MB)                                                                                        
#include <vector>
class Solution {
    void resolve(vector<vector<int>>& re, vector<int>& temp, int target, int start, vector<int>& candidates){
        if(target == 0){
            re.push_back(temp);
            return;
        }
        if(target < 0)return;

        for(int i = start; i < candidates.size(); i++){
            int j = i;
            while(j+1 < candidates.size() && candidates[j+1] == candidates[j])j++;  // 避免j+1数组越界堆溢出了
            int index = 1;
            while(i <= j){
                int ii;
                for(ii = 0; ii<index; ii++)temp.push_back(candidates[j]);
                resolve(re, temp, target - candidates[j]*index, j+1, candidates);
                index++, i++;
                for(; ii >0; ii--)temp.pop_back();  // 这是为了避免push或者pop的次数不对
            }
            i--;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        resolve(re, temp, target, 0, candidates);
        return re;
    }
};
// @lc code=end

