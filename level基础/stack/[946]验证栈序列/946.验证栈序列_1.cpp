/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;


// 时空效率提高不少..
// 奇妙的是辅助栈放在函数体内空间效率也会变高十几个点
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> a;
        int i = 0;
        for(int n : pushed){
            a.push(n);
            while(!a.empty() && a.top() == popped[i]){
                a.pop();
                i++;
            }
        }
        return a.empty();
    }
};
// @lc code=end

