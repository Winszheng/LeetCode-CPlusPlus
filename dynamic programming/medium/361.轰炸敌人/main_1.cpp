#include <vector>
#include <iostream>
using namespace std;

// 实际上这样也没有比暴力好多少
// 虽然可以用变量代替，不过没什么必要吧，思路实际没有变化
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> up(n, vector<int>(m));
        vector<vector<int>> down(up), left(up), right(up);
        // 构造左向量和上向量
        // 敌人和墙面都能构造结果
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'W')continue;  // 如果是墙，零操作
                // 构造上矩阵
                if(i>0)up[i][j] = up[i-1][j];
                // 构造左矩阵
                if(j>0)left[i][j] = left[i][j-1];
                // 如果(i, j)有敌人
                if(grid[i][j] == 'E'){
                    up[i][j]++, left[i][j]++;
                }
            }
        }
        // 构造右向量和down向量
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(grid[i][j] == 'W')continue;
                // 构造下矩阵
                if(i!=n-1)down[i][j] = down[i+1][j];
                // 构造右矩阵
                if(j != m-1)right[i][j] = right[i][j+1];
                if(grid[i][j] == 'E'){
                    down[i][j]++, right[i][j]++;
                }
            }
        }
        
        // 返回最优解
        int re = 0, tmp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != '0')continue;
                tmp = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                
                re = max(re, tmp);
            }
        }
        return re;
    }
};

int main(){
    vector<vector<char>> test1{{'0','E','0','0'}, {'E','0','W','E'},{'0','E','0','0'}};
    vector<vector<char>> test2{{'W','W','W'}, {'0','0','0'},{'E','E','E'}};
    Solution s;
    cout<<s.maxKilledEnemies(test2)<<endl;
}