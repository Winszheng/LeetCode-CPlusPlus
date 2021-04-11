/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
// 验证栈序列
// 如何验证？后进先出。
// 这是第一个10mins不到做出来的中等题，夸！
// 但运行效率和空间效率都是10%左右

// 如何改良？
// 只需要一个辅助栈即可
class Solution {
    stack<int> a, b;
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        for(int i = popped.size()-1; i>=0; i--)b.push(popped[i]);

        for(int i = 0; i<pushed.size() ;i++){
            a.push(pushed[i]);
            while(!a.empty() && a.top() == b.top()){
                a.pop();
                b.pop();
            }
        }

        return a.empty();
    }
};
// @lc code=end

