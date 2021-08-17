/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start

#include <iostream>
#include <limits.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long re = 0;
        while(x){
            re = re*10 + x%10;
            x/=10;  // 这两条式子保证re与x始终同号，且x的符号始终不变；也解决了数字以0结尾的问题
            if(re > INT_MAX)return 0;
            else if(re < INT_MIN)return 0;
        }   
        return re;  // c++自带隐式转换
    }
};


// @lc code=end

