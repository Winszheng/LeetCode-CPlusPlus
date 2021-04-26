/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;

// 题目不难，但是要注意的地方不少。
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int l = 0, r = 0, index = 0;
        map<char, string> record;
        map<string, char> re2;
        // 用两个map是为了避免有多个映射的情况
        while(r<=s.size()){
            if(r == s.size() || s[r] == ' '){
                string temp = s.substr(l, r-l);
                char c = pattern[index];
                
                if(record.find(c) == record.end() && re2.find(temp) == re2.end()){
                    record[c] = temp;
                    re2[temp] = c;
                }
                else if(record[c] != temp || re2[temp] != c)return false;

                index++;
                l = r+1;
            }
            r++;
        }
        if(index != pattern.size())return false;
        return true;
    }
};
// @lc code=end

