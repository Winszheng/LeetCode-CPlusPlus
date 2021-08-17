/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
// 思路1：暴力解法，二重循环 - 因为觉得用单调栈反而有点麻烦所以试一下，结果效率居然还不错
// 题解里更“高级”的做法也没好到哪去，不深究
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> re(n, -1);
        for(int i=0; i<n; i++){
            int j;
            for(j=0; j<m; j++){
                if(nums1[i] == nums2[j])break;
            }
            for(int k=j; k<m; k++){
                if(nums2[k] > nums2[j]){
                    re[i] = nums2[k];
                    break;
                }
            }
        }
        return re;
    }
};

// @lc code=end

