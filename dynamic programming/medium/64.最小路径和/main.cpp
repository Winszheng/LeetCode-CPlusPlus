#include <vector>
using namespace std;

// 对每个f(x, y), 结果只能来源于左or上
// 每次都取小的加和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> re(n, vector<int>(m));
        re[0][0] = grid[0][0];
        for(int i=1; i<n; i++)re[i][0] = re[i-1][0] + grid[i][0];
        for(int i=1; i<m; i++)re[0][i] = re[0][i-1] + grid[0][i];
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                re[i][j] = grid[i][j] + min(re[i-1][j], re[i][j-1]);
            }
        }
        return re[n-1][m-1];
    }
};