/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
using namespace std;
// 判断是否回文串
// 不考虑符号和大小写 
class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char n : s){
            if(isalnum(n))ss += tolower(n);
        }

        int l = 0, r = ss.size()-1;
        while(l<r){
            if(ss[l] != ss[r])return false;
            l++, r--;
        }
        return true;
    }
};
// 题目不难但是细节不少
// @lc code=end

