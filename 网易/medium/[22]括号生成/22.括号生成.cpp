/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// 把问题转化成，给定n个左括号、右括号，生成所有长为2n的合法括号串
// 生成规则：
// 1.如果左括号还有剩余，就可以使用
// 2.如果左括号的使用量大于右括号，就可以使用右括号==>即右括号的剩余量大于左括号就可以使用
// 3.每当找到一条合法结果，加入re

// 显然，这种生成方式不必担心去重问题；虽然效率比较低，但是写起来非常省事
class Solution {
public:
    vector<string> re;
    void recursion(int l, int r, int len, string s){
        if(len == 0){
            re.push_back(s);
            return;
        }
        if(l > 0)recursion(l-1, r, len-1, s+'(');
        if(r > l)recursion(l, r-1, len-1, s+')');
    }
    vector<string> generateParenthesis(int n) {
        recursion(n, n, 2*n, "");
        return re;
    }
};
// @lc code=end

