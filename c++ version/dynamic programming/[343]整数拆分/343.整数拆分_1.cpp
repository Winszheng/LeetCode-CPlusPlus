/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
// 优化的思路：按照数学规律
// 1.数字拆分出来3越多，其次2越多，最差为1，乘积最大
// 2.如果最终拆出来有1，拿一个3出来组成4，能让乘积最大化

// 
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        int nn = n/3;
        int re = n%3;
        if(re == 0)return (int)pow(3, nn);
        else if(re == 1)return (int)pow(3, nn-1)*4;
        else return (int)pow(3, nn)*2;
    }
};
// @lc code=end

