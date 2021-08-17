/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
// 循环遍历数组寻找下一个更大元素，本质上并不需要真正循环，只要把遍历范围扩大一倍即可
// step 1：栈不空且操作元素＞栈顶，出栈
// step 2：栈空或操作元素小于栈顶，入栈
// 另一种形式的if-else
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> re(n, -1);
        stack<int> s;
        for(int i=0; i<n*2; i++){
            while(!s.empty() && nums[i%n] > nums[s.top()]){
                re[s.top()] = nums[i%n];
                s.pop();
            }
            // 栈空或操作元素小于栈顶
            s.push(i%n);
        }
        return re;
    }
};
// @lc code=end

