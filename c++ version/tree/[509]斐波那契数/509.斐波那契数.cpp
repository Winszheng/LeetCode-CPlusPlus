/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n == 0)return 0;
        if(n == 1)return 1;
        int a = 0, b = 1, t;
        for(int i=2;i<n+1;i++){
            t = a;
            a = b;
            b = a + t;
        }
        return b;
    }
};
// @lc code=end

