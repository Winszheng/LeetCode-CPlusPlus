/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
// 经典回溯题

// 如何判断是否同一对角线？相减定值，相加定值
// 正对角线：相减定值, 加个n-1来凑下标 ==> 0...2*n-2
// 反对角线：相加定值                ==> 0...6 还挺省事的

// 结果的时空效率都不错
class Solution {
    vector<bool> col, dia1, dia2;   
    vector<vector<string>> re;
    vector<string> generate(vector<int>& temp, int n){
        vector<string> r = vector<string>(n, string(n, '.'));
        for(int i = 0; i<n;i++)r[i][temp[i]] = 'Q';
        return r;
    }
    void resolve(int n, int index, vector<int>& temp){
        if(index == n){
            re.push_back(generate(temp, n));
            return;
        }
        for(int i = 0;i<n;i++){ //查哪一列可用
            if(!col[i] && !dia1[i-index+n-1] && !dia2[index+i]){
                temp.push_back(i);
                col[i] = true, dia1[i-index+n-1] = true, dia2[index+i] = true;
                resolve(n, index+1, temp);
                col[i] = false, dia1[i-index+n-1] = false, dia2[index+i] = false;
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp;
        col = vector<bool>(n, false);
        dia1 = dia2 = vector<bool>(2*n-1, false);
        resolve(n, 0, temp);
        return re;
    }
};


// @lc code=end

