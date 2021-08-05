/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

// 莫名其妙就一遍过了...
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int p1 = 0, p2 = 0, p=0;
        vector<int> re(n+m, 0);
        while(p1<n && p2<m){
            if(nums1[p1] < nums2[p2]){
                re[p] = nums1[p1];
                p++, p1++;
            }else{
                re[p] = nums2[p2];
                p++, p2++;
            }
        }
        while(p1 < n){
            re[p] = nums1[p1];
            p++, p1++;
        }
        while(p2 < m){
            re[p] = nums2[p2];
            p++, p2++;
        }
        int mid = (n+m)/2;
        if((n+m) % 2 == 1)return (double)re[mid];
        return (re[mid-1] + re[mid])*1.0/2;
    }
};
// @lc code=end

