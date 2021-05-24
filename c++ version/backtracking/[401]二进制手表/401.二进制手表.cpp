/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start

// 简单题，但一时之间没有思路
// 根本上这个题不该用回溯去写，因为不优雅并且小题大做
// 对数据量不敏感没考虑到可以直接枚举

class Solution {
    int count(int n){   // 计算2进制中1的数量
        int re = 0;
        while(n != 0){
            n = n & (n-1);
            re++;
        }
        return re;
        
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> re;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(count(i) + count(j) == turnedOn){
                    if(j > 9)re.push_back(to_string(i) + ":" + to_string(j));
                    else re.push_back(to_string(i) + ":0" + to_string(j));
                }
            }
        }
        return re;
    }
};
// @lc code=end

