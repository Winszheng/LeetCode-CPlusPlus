/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start

// 对撞指针，真香
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            swap(s[l], s[r]);
            l++, r--;
        }
    }
};
// @lc code=end

