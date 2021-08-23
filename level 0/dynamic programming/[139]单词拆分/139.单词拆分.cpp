/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
// define dp[i] 表[0..i-1]是否可以拆成字典中的单词
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> temp;
        for(string s : wordDict)temp.insert(s);
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;   // 空串默认为true
        for(int i=1;i<n+1;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && temp.find(s.substr(j, i-j))!=temp.end())dp[i] = true;
            }
        }
        return dp[n];
    }
};
// @lc code=end

