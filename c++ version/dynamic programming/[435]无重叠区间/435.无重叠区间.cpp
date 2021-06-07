/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start

// define dp[i] : 表示到第i个区间为之，不重叠的区间有几个
// 注意dp数组的下标比区间数组大1
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=1;i<n;i++){ 
            int j = i-1;
            while(j>=0 && intervals[i][0] < intervals[j][1])j--;
            if(j < 0)dp[i+1] = 1;
            else dp[i+1] = dp[j+1] + 1;
        }
        return n - dp[n];
    }
};
// @lc code=end

