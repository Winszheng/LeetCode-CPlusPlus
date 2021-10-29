#include <vector>
using namespace std;

// 思路和间隔房屋偷盗是一样的，区别：首尾不能同时选中
// define dp[i]为0-i上能拿到的最优解
class Solution {
public:
    int resolve(vector<int> nums){
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        int a = nums[0], b = max(nums[0], nums[1]), c;
        for(int i=2; i<n; i++){
            c = max(b, a+nums[i]);
            a = b, b = c;
        } 
        return c;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        int a = resolve(vector<int>(nums.begin(), nums.end()-1));
        int b = resolve(vector<int>(nums.begin()+1, nums.end()));
        return max(a, b);
    }
};