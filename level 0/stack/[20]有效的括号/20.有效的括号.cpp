/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

// 两个事情
// 1.思路没有问题，括号匹配本质上和回退步骤是一样的
// 2.对stl不熟悉导致错误，当stack为空时，直接查top()会报段错误
// 改良思路：
// 使用映射把括号设为k-v值

class Solution {
public:
    bool isValid(string s) {
        string ss();
        stack<char> ch;
        for(char c: s){
            if(c == '(' || c=='[' || c=='{')ch.push(c);
            else if(c==')'){
                if (!ch.empty() && ch.top() == '(') {
                    ch.pop();
                } else {
                    return false;
                }
            }else if(c == ']'){
                if (!ch.empty() && ch.top() == '[') {
                    ch.pop();
                } else {
                    return false;
                }
            }else if(c == '}'){
                if (!ch.empty() && ch.top() == '{') {
                    ch.pop();
                } else {
                    return false;
                }
            }
        }

        if(ch.empty())return true;
        return false;

    }
};

// @lc code=end

