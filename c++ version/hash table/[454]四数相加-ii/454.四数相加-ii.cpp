/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
// 四个数组，各挑一个，要求加和为0
// 找到所有元组，返回数量即可
// 1.暴力的解法：O(n^4)

// 2.优化：哈希表
// 把nums3、nums4放到哈希表里，可以降低为二重循环，应该ok
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> record; // 结果，频率
        for(int n : nums3){
            for(int m : nums4)record[n+m]++;    // c++里哈希表会默认初始化
        }
        int re = 0;
        for(int n : nums1){
            for(int m : nums2){
                int sum = n + m;
                re += record[0-sum];
            }
        }
        return re;
    }
};
// @lc code=end

