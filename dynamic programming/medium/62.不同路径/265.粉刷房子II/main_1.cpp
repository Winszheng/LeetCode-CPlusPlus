#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// n个房子， k个色
// 要求O(nk)复杂度

// 实际上利用的只是上一个状态的最小和次小，实际只是几个状态之间的转移

// 典型的记忆化搜索：
// 上一个状态的最优解、次优解、最优解对应的下标
// 当然，在搜索当前状态时，也需要记忆当前状态的三个属性，并在计算完毕之后完成赋值

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k=costs[0].size();
        int t1=0, t2=0, n1 = INT_MAX; 
        int tt1, tt2, nn1, tmp;
        for(int i=0; i<n; i++){
            tt1 = INT_MAX, tt2 = INT_MAX;
            for(int j=0; j<k; j++){
                tmp = costs[i][j];
                if(j == n1)tmp += t2;
                else tmp += t1;
                if(tmp < tt1){
                    tt2 = tt1;
                    tt1 = tmp, nn1 = j;
                }else if(tmp < tt2)tt2 = tmp;
            }
            t1 = tt1, t2 = tt2, n1 = nn1;
        }
        return t1;
    }
};

int main(){
    vector<vector<int>> test{{1,5,3}, {2,9,4}};
    Solution s;
    cout<<s.minCostII(test)<<endl;
}