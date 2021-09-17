// 1.暴力解法必然超时
// 2.滑动窗口
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,t=1,n=nums.size(),re=0;
        // 每次都求以r为端点的所有符合条件的结果
        while(r<n){
            t *= nums[r];r++;
            while(l<r && t >= k){
                t /= nums[l];l++;
            }
            re += r-l;
        }
        return re;
    }
};