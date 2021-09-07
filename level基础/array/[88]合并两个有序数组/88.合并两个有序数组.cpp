/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
// 本质上这道题在做归并操作
// 倒着做会比较合适

// 额，虽然不喜欢但是要接收那种--++的写法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums1[m]>nums2[n]){
                nums1[i] = nums1[m];
                m--;
            }else{
                nums1[i] = nums2[n];
                n--;
            }
            i--;
        }
        while(m>=0)nums1[i--]=nums1[m--];
        while (n>=0)nums1[i--]=nums2[n--];
        
    }
};
// @lc code=end

