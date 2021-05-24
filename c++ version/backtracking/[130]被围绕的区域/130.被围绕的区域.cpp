/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
// floodfill算法
// 把不被围绕的O块改成#块，赋值其他块
// 把#块改回O块

// 有点蠢但是效率还不错
// Your runtime beats 99.56 % of cpp submissions
// Your memory usage beats 83.7 % of cpp submissions (9.7 MB)

class Solution {
    int n, m;
    int loc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};//(i, j)
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void resolve(vector<vector<char>>& b, int i, int j){
        b[i][j] = '#';
        for(int ii=0; ii<4; ii++){
            int newi = i+loc[ii][0], newj = j+loc[ii][1];
            if(isValid(newi, newj) && b[newi][newj] == 'O')resolve(b, newi, newj);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            if(i==0 || i==n-1){
                for(int j = 0; j < m; j++){
                    if(board[i][j] == 'O')resolve(board, i, j);
                }
            }else{
                if(board[i][0] == 'O')resolve(board, i, 0);
                if(board[i][m-1] == 'O')resolve(board, i, m-1);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != '#')board[i][j]='X';
                else board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end

