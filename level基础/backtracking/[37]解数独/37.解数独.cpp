/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

// 效率一般，但是过了，而且代码和思路都很简单
// 思路：
// 1.遍历每个空隙，做深搜，只要找到可行解，就返回
// 2.深搜的截止条件：
    // 每个空隙都填满了
    // 找到了可行解一路return true回去
// 难点在于对true和false的return
class Solution {
    bool isvalid(vector<vector<char>>& b, int k, int i, int j){
        for(int ii=0;ii<9;ii++)if(b[ii][j] == k)return false;
        for(int jj=0;jj<9;jj++)if(b[i][jj] == k)return false;
        int ii = i/3*3, jj = j/3*3;
        for(i = ii; i<ii+3;i++){
            for(j=jj;j<jj+3;j++){
                if(b[i][j] == k)return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& b){
        for(int i=0; i < 9; i++){
            for(int j=0; j < 9; j++){
                if(b[i][j]!='.')continue;
                // 找到空隙之后，逐个尝试能用的数字
                for(int k='1';k<='9';k++){
                    if(isvalid(b, k, i, j)){
                        b[i][j] = k;
                        if(dfs(b))return true;  // 找到了可行解
                        b[i][j] = '.';  // 没找到，赋值回去，因为isvalid要用
                    }
                }
                // 如果没有在上一部分return回去，证明这个求解思路不行，应该让上一层调用回溯
                return false;
            }
        }
        return true;    // 所有空隙都填满了，直接返回true
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};

// int main(){
//     vector<vector<char>> b = {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'}
//     };
//     Solution s;
//     s.solveSudoku(b);
//     for(int i = 0; i<9; i++){
//         for(int j=0;j<9;j++){
//             cout<<b[i][j]<<", ";
//         }
//         cout<<endl;
//     }
// }
// @lc code=end

