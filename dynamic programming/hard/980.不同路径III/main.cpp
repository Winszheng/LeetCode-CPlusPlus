#include <vector>
#include <iostream>
using namespace std;

// hard: 华为机考的时候竟然没做出来...内存100.00% 时间99.07%
// 四个方向都能走，求所有路径的数量——典型的深搜+回溯——不是dp
// 1.搜索的深度是步长(依靠步长停止递归、判断是否找到解) —— 递归深度 —— 说是h+1也没问题，反正是线性关系
// 2.每到一个坐标，搜索它的四个方向，搜索的次数是h+1(最后一次要搜索是否到达终点，是特殊的) —— 最后一步
// ps.因为是深搜的关系，可以通过传引用减少内存消耗
class Solution {
public:
    int re = 0, n, m; // 结果
    // 剩余需要处理的步长 当前所在的坐标 深搜地图
    void resolve(int h, int x, int y, vector<vector<int>>& grid){   
        if(h==0){   // 有可能走完所有步长时，下一步无法到终点
            if(x>0 && grid[x-1][y]==2)re++; 
            if(x<n-1 && grid[x+1][y]==2)re++;
            if(y>0 && grid[x][y-1]==2)re++;
            if(y<m-1 && grid[x][y+1]==2)re++;
        }

        if(x>0 && grid[x-1][y]==0){ 
            grid[x-1][y] = 1;
            resolve(h-1, x-1, y, grid);
            grid[x-1][y] = 0;
        }
        if(x<n-1 && grid[x+1][y]==0){
            grid[x+1][y] = 1;
            resolve(h-1, x+1, y, grid);
            grid[x+1][y] = 0;
        }
        if(y>0 && grid[x][y-1]==0){
            grid[x][y-1] = 1;
            resolve(h-1, x, y-1, grid);
            grid[x][y-1] = 0;
        }
        if(y<m-1 && grid[x][y+1]==0){
            grid[x][y+1] = 1;
            resolve(h-1, x, y+1, grid);
            grid[x][y+1] = 0;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int h = 0, x, y;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0)h++;
                if(grid[i][j] == 1){x=i, y=j;}
            }
        }
        resolve(h, x, y, grid);
        return re;
    }
};

int main(){
    vector<vector<int>> grid{{1,0,0,0}, {0,0,0,0},{0,0,2,-1}};
    Solution s;
    cout<<s.uniquePathsIII(grid)<<endl;
}
