#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, re=INT_MAX, n=nums.size(), t=0;
        while(r<n){
            t += nums[r];r++;
            while(t >= target){
                re = min(re, r-l);
                t -= nums[l];
                l++;
            }
        }
        return re==INT_MAX ? 0 : re;
    }
};





int main(){
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    cout<<s.minSubArrayLen(7, nums)<<endl;
}