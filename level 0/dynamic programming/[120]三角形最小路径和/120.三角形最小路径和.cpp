/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
// 求三角形自顶向下的路径和，注意：得相邻
// 思路虽然是动态规划的，把大问题分解成小问题
// 但是写起来说是很朴素的迭代也没毛病
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1)return triangle[0][0];
        if(triangle.size() == 2)return min(triangle[0][0]+triangle[1][0], triangle[0][0]+triangle[1][1]);
        for(int i = triangle.size()-2; i>=0; i--){
            for(int j = 0; j<triangle[i].size(); j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end

