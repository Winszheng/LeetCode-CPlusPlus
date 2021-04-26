/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start

// s和t的关系是一一映射
#include <map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> record, re;
        for(int i = 0; i<s.size(); i++){
            char a = s[i], b = t[i];
            if(record.find(a) == record.end() && re.find(b) == re.end()){
                record[a] = b;
                re[b] = a;
            }
            else if(record[a] != b || re[b] != a)return false;
        }
        return true;

    }
};
// @lc code=end

