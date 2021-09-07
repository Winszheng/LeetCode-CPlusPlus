#include <vector>
using namespace std;
// 思路1：暴力解法，每次都找上一状态中除了同色之外成本最低的颜色，这样复杂度相当于n*k*k
// 因为k可以当做常数，所以猜测不会超时?
// 结果不仅没超，效率还95%...

// 这题出得不好
// 但也侧面说明，不写白不写
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size(), k=costs[0].size();
        vector<vector<int>> d(n, vector<int>(k));
        for(int i=0; i<k; i++)d[0][i]=costs[0][i];

        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                int temp=INT_MAX;
                for(int h=0;h<k;h++){
                    if(h!=j)temp=min(temp, d[i-1][h]);
                }
                d[i][j] = costs[i][j] + temp;
            }
        }

        int temp = INT_MAX;
        for(int i=0;i<k;i++)temp=min(temp, d[n-1][i]);
        return temp;
    }
};