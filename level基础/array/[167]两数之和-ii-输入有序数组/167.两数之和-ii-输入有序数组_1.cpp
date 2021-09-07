/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// 方法一：暴力解法 O(n) —— 这个题会超时
// 方法二：二分法——因为数组本身有序, O(nlogn)
// 方法三：双指针(对撞指针)，O(n),妙啊——注意，采取内移策略，不会漏掉解
// 左侧先到，一定大了，
// 右侧先到，一定小了

// 双指针真好用， 比二分法更省事
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l < r){
            int re = numbers[l] + numbers[r];
            if(re == target)return {l+1, r+1};
            else if(re < target)l++;
            else r--;
        }
        return {-1, -1};
    }
};
// @lc code=end

