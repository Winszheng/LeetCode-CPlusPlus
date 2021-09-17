#include <vector>
#include <stack>
using namespace std;
// 039.计算直方图的最大矩形面积
// 1.暴力的解法：对每一个直方图高度，用双指针向左向右探索，获取这个高度能匹配的最大矩形
//      即，一重循环+双指针，基本上等于二重循环
// 2.优化后的O(n)解法：单增栈，大于栈顶，压栈；小于栈顶，出栈并计算
// 根据栈先进后出的数据结构，单增栈会有这样的特点：
// 对栈中每一个元素来说，它底下的一个元素，是上一个小于它的元素，不管这中间进行了多少次出栈入栈的操作
// 因此，在计算矩形宽度的时候，需要用栈顶的下一个元素下标来计算；如果栈顶之下没有元素，那么栈顶自然是当前所有元素中的最小
// 因此这个做法的思路本质上和暴力解法是一样的，只是时间上做了优化

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int re = 0;
        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int h = heights[s.top()];s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                re = max(re, h*w);
            }
            s.push(i);
        }
        return re;
    }
};

// case: 4 2 0 3 2 5
// result: 6