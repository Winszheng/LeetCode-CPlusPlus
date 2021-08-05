/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
// q：求回文子串的数量
// 对每个字符，求以其为中心的奇数回文子串、偶数回文子串的总数

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            // 求奇数回文子串
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--, r++;
                sum++;
            }
            l=i, r=i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                l--, r++;
                sum++;
            }
        }
        return sum;
    }
};
// @lc code=end

