#include <vector>
#include <iostream>
using namespace std;

// 不用数组，只用变量
// 时空效率很不错

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0], b = cost[1], tmp;
        for(int i=2;i<n;i++){
            tmp = b;
            b = min(a, b)+cost[i];
            a = tmp;
        }
        return min(a, b);
    }
};

int main(){
    Solution s;
    vector<int> temp1{10, 15, 20};
    vector<int> temp2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<s.minCostClimbingStairs(temp1)<<endl;
    cout<<s.minCostClimbingStairs(temp2)<<endl;
}