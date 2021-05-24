/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start

// 思路：从左上角和右上角分别放水，重合的坐标就是答案

class Solution {
    vector<vector<bool>> a, b;
    vector<vector<int>> re;
    int n, m;
    int loc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isvalid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void resolve(vector<vector<int>>& bo, vector<vector<bool>> &visited, int i, int j){
        if(visited[i][j])return;    // 在这里查是为了避免压入重复坐标
        visited[i][j] = true;
        if(a[i][j] && b[i][j])re.push_back({i, j}); // 重合的部分

        for(int ii=0; ii<4; ii++){
            int newi = i+loc[ii][0], newj = j+loc[ii][1];
            if(isvalid(newi, newj) && bo[newi][newj] >= bo[i][j])resolve(bo, visited, newi, newj);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // if(heights.empty())return re;
        n = heights.size(), m = heights[0].size();
        a = b = vector<vector<bool>>(n, vector<bool>(m, false));   // 初始化两个辅助数组


        for(int i = 0; i < n; i++){
            resolve(heights, a, i, 0);  // 左
            resolve(heights, b, i, m-1);    // 右
        }
        for(int j = 0; j < m; j++){
            resolve(heights, a, 0, j);  // 上
            resolve(heights, b, n-1, j);    // 下
        }
        return re;
    }
};
// @lc code=end

