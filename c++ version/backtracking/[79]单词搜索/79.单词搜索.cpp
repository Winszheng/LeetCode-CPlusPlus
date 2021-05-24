/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
// 思路：每次探索完一个字符之后，往四个方向探索，那么要求
// 1.方向合法且不是回头路——需要有机制保证方向合法且不走回头路
// 2.探索到最后一个字符，符合返回true，不符合返回false

// 之前遇到了玄学问题，自己电脑结果和leetcode不一样，一晚上折腾不出来
// 今天重写就好了

// 本质上这个题思路和一维回溯是一样的

class Solution {
    int n, m;   // (i, j)
    int loc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};   // 偏移量数组：左右上下 (i, j)
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    bool resolve(vector<vector<char>>& b, string& s, int index, int i, int j){
        if(index == s.size()-1)return s[index] == b[i][j];

        if(b[i][j] != s[index])return false;
        b[i][j] = '#';
        for(int ii = 0; ii < 4; ii++){
            int newi = i + loc[ii][0], newj = j + loc[ii][1];
            if(isValid(newi, newj) && b[newi][newj] != '#' && resolve(b, s, index+1, newi, newj))return true;             
        }
        b[i][j] = s[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(resolve(board, word, 0, i, j))return true;
            }
        }
        return false;
    }
};
// @lc code=end

