/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
// 想到于套多一层循环的84.求柱状图中的最大矩形
// 把每行都作为坐标轴，计算一遍能获取的“柱状图最大矩形”，
// 计算方法：单调栈，栈空or大于栈顶，把坐标压栈；
// 否则，栈不空且探测元素小于栈顶，逐个出栈并计算能获取的所有矩形的值，不断更新最优解，最后把探测元素压栈
// 关键是，width的选择，因为栈压栈出栈的特性，如果能到栈空的程度，探测值一定是当前最小；
// 如果不能出到栈空，拿到的就是“局部最小”，所以w = s.empty() ? j : j-s.top()-1

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)return 0;
        int m = matrix[0].size();
        int re = 0;

        vector<int> temp(m+1, 0);
        temp[m] = INT_MIN;
        for(int i=0; i<n; i++){
            // 1.构造柱形图
            for(int j=0;j<m;j++){
                temp[j] = matrix[i][j]=='0' ? 0 : temp[j]+1;
            }
            // 2.构造单调栈并计算
            stack<int> s;
            for(int j=0; j<m+1; j++){
                // 注意pop的时机
                while(!s.empty() && temp[j] < temp[s.top()]){
                    int h = temp[s.top()]; s.pop();
                    int w = s.empty() ? j : j-s.top()-1; // 关键
                    re = max(re, w*h);
                }
                s.push(j);
            }
        }
        return re;
    }
};

// 012 3


// @lc code=end