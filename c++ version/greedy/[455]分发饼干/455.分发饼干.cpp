/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
// 贪心算法：
// 每次都操作最大的饼干，用来满足刚刚好能满足的那个小朋友
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int re = 0, j = g.size()-1;
        for(int i = s.size()-1; i >=0; i--){
            while(j>=0 && g[j] > s[i])j--;
            if(j >= 0){
                re++, j--;
            }
        }
        return re;
    }
};
// @lc code=end

