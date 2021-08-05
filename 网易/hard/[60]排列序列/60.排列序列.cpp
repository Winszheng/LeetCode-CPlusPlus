/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 求各阶乘
        vector<int> fa(n, 0);
        fa[0] = 1;
        for(int i=1; i<n; i++)fa[i] = i*fa[i-1];

        vector<int> nums(n, 0);
        for(int i=0;i<n;i++)nums[i] = i+1;
        string re;

        k--;    // 数组下标是从 0 开始，k 首先要减去 1
        for(int i=1; i<=n; i++){
            int t = k/fa[n-i];
            re.push_back(nums[t] + '0');
            k %= fa[n-i];

            for(int j=t; j<n-1; j++)nums[j] = nums[j+1];
        }
        return re;
    }
};

// 1.堆溢出：数组越界or下标错误
// @lc code=end

