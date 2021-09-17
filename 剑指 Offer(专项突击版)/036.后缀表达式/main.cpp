#include <stack>
#include <string>
#include <vector>
using namespace std;

// 逆波兰表达式求解
// 数字入栈
// 遇到符号，弹栈求解再压栈
// 最后返回栈顶

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string ss : tokens){
            if(ss=="+"||ss=="-"||ss=="*"||ss=="/"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(ss == "+")s.push(a+b);
                else if(ss == "-")s.push(a-b);
                else if(ss == "*")s.push(a*b);
                else s.push(a/b);
                continue;
            }
            s.push(stoi(ss));
        }
        return s.top();
    }
};

// 逆波兰表达式求解，应该是刻在dna里的啊！！！！