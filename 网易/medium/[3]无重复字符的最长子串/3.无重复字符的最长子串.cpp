/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// 滑动窗口，如果没有重复字符，就一直扩展右边
// 如果遇到重复字符，就收束左边，直到把与右端相同的字符排除窗外
// 滑动窗口要划过整个区
// 理解了思路之后就能一遍过
// 因为字符的特殊性，没必要用set表征是否存在，用vector就够了

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=-1;
        vector<int> win(255, 0);    // 表字符在窗口的存在性，1为存在，0为不存在
        int n = s.size(), re=0;
        while(l < n){
            if(r+1<n && win[s[r+1]]==0){
                win[s[r+1]] = 1;
                r++;
            }else{
                win[s[l]] = 0;
                l++;
            }
            re = max(re, r-l+1);
        }
        return re;
    }
};
// @lc code=end

