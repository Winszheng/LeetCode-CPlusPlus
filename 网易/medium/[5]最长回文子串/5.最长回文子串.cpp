/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
// 思路：对每个字符，寻找以它为中心的奇数偶数回文串，不断记录当前最好的结果
// 一遍过，本题思路和647.求回文子串数量是一模一样的
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1, pos = 0;
        for(int i=0; i<n; i++){
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--, r++;
            }
            if(r-l-1 > len){
                len = r-l-1;
                pos = l+1;
            }
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--, r++;
            }
            if(r-l-1 > len){
                len = r-l-1;
                pos = l+1;
            }
        }
        string re = s.substr(pos, len);
        return re;
    }
};
// @lc code=end

