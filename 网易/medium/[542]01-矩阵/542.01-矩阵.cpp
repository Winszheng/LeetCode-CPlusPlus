/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
#include <vector>
#include <limits.h>
using namespace std;

// dp
// 1.先赋初始值, 默认所有步长都是无限远/0值
// 2.从左上角和右下角分别搜索一遍, 不断保存最优步长, 相当于：
// 第一遍保存了左、上的最优解
// 第二遍保存了下、右的最优解
// 于是整个re存储了最优解
class Solution {
public: 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> re(n, vector<int>(m, INT_MAX/2));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0)re[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i > 0)re[i][j] = min(re[i][j], re[i-1][j] + 1);
                if(j > 0)re[i][j] = min(re[i][j], re[i][j-1] + 1);
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i < n-1)re[i][j] = min(re[i][j], re[i+1][j] + 1);
                if(j < m-1)re[i][j] = min(re[i][j], re[i][j+1] + 1);
            }
        }
        return re;
    }
};
// @lc code=end

