/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
// todo：返回峰值元素所在索引
// 二分法，峰值元素一定在大的那里
#include <vector>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid] < nums[mid+1])l=mid+1;
            else r = mid;
        };
        
        return l;
        
    }
};


// @lc code=end
