#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

// 方法1：
// 定义状态 fx : 到达x所需的最小跳跃数
// 对每个当前位置，更新后续所有位置的最小值

// 过了，但时空效率很低下

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX/2); dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+nums[i] && j<n; j++){
                dp[j] = min(dp[i]+1, dp[j]);
            }
        }
        return dp[n-1];
    }
};


int main() {
    vector<int> test1{2, 3, 1, 1, 4};
    Solution s;
    cout<<s.jump(test1)<<endl;
}