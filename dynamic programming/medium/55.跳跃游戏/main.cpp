#include <vector>
#include <iostream>
using namespace std;
// 跳跃游戏 —— 这道题，怪就怪tmd我没有认真看测例！
// 最后一步能跳的范围需要超过或等于终点坐标
// 对每一步，判断是否超过可达点，超过说明失败
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), re = 0;
        for(int i=0;i<n;i++){
            if(i > re)return false;
            re = max(re, i+nums[i]);
        }
        return true;
    }
};
