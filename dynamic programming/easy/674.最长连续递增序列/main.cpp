#include <vector>
using namespace std;

// 对每个fx, 如果大于上一个元素，tmp++，并尝试更新re
// 否则，tmp=1
// 典型又简单的dp
// 一遍过
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int re = 1, tmp = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1])tmp++;
            else tmp = 1;
            re = max(re, tmp);
        }
        return re;
    }
};