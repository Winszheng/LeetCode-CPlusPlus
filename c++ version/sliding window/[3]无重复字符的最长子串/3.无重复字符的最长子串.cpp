/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// 这道题比刚刚的难一点，但不是难在代码，而是难在思路
// 而且只要想清楚了，代码就很简单
// 解法：滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1, res = 0; // [l, r]
        int fre[255] = {0}; //把所有字符的出现频率初始化为0
        // 右端不重复，拓展右端
        // 右端重复，右端不扩展，不断收束左端——按我之前的做法，会多套一层while，没必要
        while(l < s.size()){
            if(r+1 < s.size() && fre[s[r+1]] == 0){
                fre[s[++r]]++;
            }else{
                fre[s[l++]]--;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
// @lc code=end

