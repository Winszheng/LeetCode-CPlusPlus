/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
// 求n皇后问题的解法
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.99 % of cpp submissions
// 和51思路一样，少了储存中间结果和最终结果，代码和效率更高了
class Solution {
    vector<bool> col, dia1, dia2;
    int re;
    void resolve(int n, int index){
        if(index == n){
            re++;
            return;
        }
        for(int i=0; i<n; i++){
            if(!col[i] && !dia1[i+index] && !dia2[i-index+n-1]){
                col[i] = true, dia1[i+index] = true, dia2[i-index+n-1] = true;
                resolve(n, index+1);
                col[i] = false, dia1[i+index] = false, dia2[i-index+n-1] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        dia1 = dia2 = vector<bool>(2*n-1, false);
        re = 0;
        resolve(n, 0);
        return re;
    }
};
// @lc code=end

