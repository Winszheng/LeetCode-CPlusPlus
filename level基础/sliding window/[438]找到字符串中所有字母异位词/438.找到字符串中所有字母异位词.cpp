/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
// vector可以直接用==做比较，前提是vector里存的东西可以直接比较
// 解法：滑动窗口
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l, r;
        vector<int> a(26, 0), b(26, 0), res;
        int n = s.size(), m = p.size(); //  登记频率
        if(m>n)return res;

        for(int i=0; i<m; i++){
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        if(a == b)res.push_back(0);
        l = 0, r = m-1;
        // while(r < n){
        //     a[s[l] - 'a']--;
        //     l++, r++;
        //     a[s[r] - 'a']++;
        //     if(a == b)res.push_back(l);
        // } ==> 我真的没看出来这段有什么问题，但是过不了leetcode，换成下面的for就ok
        // 真tm郁闷
        for(int i = m; i<n; i++){
            a[s[i]-'a']++;
            a[s[i-m] - 'a']--;
            if(a == b)res.push_back(i-m+1);
        }
        return res;
    }
};
// @lc code=end

