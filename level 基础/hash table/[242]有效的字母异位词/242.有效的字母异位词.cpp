/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// 虽然写着hash table，但是我觉得这个题用vector比较方便
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> temp(128, 0);
        for(char c : s)temp[c]++;
        for(char c : t)temp[c]--;
        for(int i = 'a'; i<= 'z'; i++){
            if(temp[i] != 0)return false;
        }
        return true;
    }
};
// @lc code=end

