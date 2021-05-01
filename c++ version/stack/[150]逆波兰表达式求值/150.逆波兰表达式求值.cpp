/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
using namespace std;
// 逆波兰表达式——后缀表达式，栈的经典运用
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for(string s : tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                 int a = temp.top();temp.pop();
                 int b = temp.top();temp.pop();
                if(s=="+")temp.push(a+b);
                if(s=="-")temp.push(b-a);
                if(s=="*")temp.push(a*b);
                if(s=="/")temp.push(b/a);
            }else temp.push(stoi(s));
        }
        return temp.top();
    }
};
// @lc code=end

