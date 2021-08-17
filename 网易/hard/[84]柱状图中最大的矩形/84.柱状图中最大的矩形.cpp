/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

// 思路1：二重循环 O(n^2) ==> 错了，会超时
// 思路2：参考求回文子串，以每个柱作为高度，左右扩展，不断求最优值 ==> 超时，毕竟依然是O(n^2)
// 思路3：单调栈
// 1.构造一个单调递增的栈，每当遇见栈不空且当前元素小于栈，出栈
// 2.并以当前出栈元素构造矩形，获取当前最优值
// 3.为了当栈中最后剩余的元素也能被计算，给原数组增加一个0

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int re = 0;
       stack<int> s;
       heights.push_back(0);  // 为了最后也能计算栈中剩余的结果
       int n = heights.size();
       for(int i=0; i<n; i++){
           while(!s.empty() && heights[s.top()] > heights[i]){
               int h = heights[s.top()]; s.pop();
               int w = s.empty() ? i : i-s.top()-1;
               re = max(re, w*h);
           }
           s.push(i);
       }
       return re;
    }
};

// int main(){
//     vector<int> s = {2,1,2};
//     Solution ss;
//     cout<<ss.largestRectangleArea(s)<<endl;
// }
// @lc code=end

