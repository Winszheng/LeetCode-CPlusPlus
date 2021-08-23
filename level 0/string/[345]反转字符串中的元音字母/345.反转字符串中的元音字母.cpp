/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
// aeiou
#include <string>
using namespace std;
class Solution {
    bool judge(char c){
        char cc[] = {'a', 'e', 'i','o','u','A','E','I','O','U'};
        for(char n : cc){
            if(c == n)return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        
        while(l<r){
            while(!judge(s[l]) && l<r){
                l++;
            }
            while(!judge(s[r]) && l<r){
                r--;
            }
            
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};

// @lc code=end

