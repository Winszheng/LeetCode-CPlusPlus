/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
// 贪心算法，用两个指针做比较
// 这写法也不是不可以，但是我觉得，不够好理解
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(s[i] == t[j])i++;
            j++;
        }
        return i==n;
    }
};
// @lc code=end

