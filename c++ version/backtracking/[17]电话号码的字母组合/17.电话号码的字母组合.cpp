/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

// 朴素的思路是循环，但是绝对不可能用循环写的，这是典型的递归题，在递归的过程中求出所有结果
// 与其说是递归，更像是自顶向下的树形问题

#include <string>
#include <vector>
using namespace std;
class Solution {
    string letter[10] = {   // 类里定义数组需要写清楚大小
        "", "", // 0 1
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
public:
    void resolve(vector<string>& re, string digits, int index, string temp){
        if(index == digits.size()){
            re.push_back(temp);
            return;
        }
        for(char c : letter[digits[index] - '0']){
            resolve(re, digits, index+1, temp+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> re;
        if(digits == "")return re;
        resolve(re, digits, 0, "");
        return re;
    }
};
// @lc code=end

