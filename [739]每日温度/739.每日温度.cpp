/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
// 思路：单调递减栈
// 1.栈不空且当前操作值大于栈顶，记录结果并出栈
// 2.否则，即栈空或操作值小于栈顶，压栈
// 单调栈的if-else并不直观，因为蕴含了常数级的循环
// 基本上讲，单调栈的复杂度在O(n)到O(n^2)之间
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> re(n, 0);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                re[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return re;
    }
};
// @lc code=end

