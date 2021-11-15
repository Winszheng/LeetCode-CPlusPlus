#include <vector>
using namespace std;

// 朴素做法：把每个可探测位试探一遍
// 能过但时空效率很低
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int re = 0, n = grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // 遇到一个可探测位
                if(grid[i][j] == '0'){
                    int tmp = 0;
                    // 上下左右各找一遍
                    int ii = i-1, jj = j-1;
                    while(ii>=0 && grid[ii][j]!='W'){if(grid[ii][j] == 'E')tmp++; ii--;}
                    ii = i+1;
                    while(ii<n && grid[ii][j] != 'W'){if(grid[ii][j] == 'E')tmp++; ii++;}
                    while(jj>=0 && grid[i][jj] != 'W'){if(grid[i][jj] == 'E')tmp++; jj--;}
                    jj = j+1;
                    while(jj<m && grid[i][jj] != 'W'){if(grid[i][jj] == 'E')tmp++; jj++;}
                    re = max(re, tmp);
                }
            }
        }
        return re;
    }
};