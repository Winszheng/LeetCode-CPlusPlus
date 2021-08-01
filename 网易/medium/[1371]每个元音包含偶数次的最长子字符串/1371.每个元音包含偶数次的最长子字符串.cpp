/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start

// 思路：有限自动状态机

#include <string>
#include <iostream>
#include <vector>
#include "limits.h"
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> re(32, INT_MAX);
        int cur = 0, ans = 0;
        int n = s.size();
        re[0] = -1; // 因为状态0确实出现在下标为-1的位置处, 
                    // 如果也设置为INT_MAX, 那第1次运算到pre[0]时就不是第1次出现状态0, 而是第2次出现状态0了
        for(int i=0; i<n; i++){
            switch(s[i]){
                case 'a': cur ^= 1;
                case 'e': cur ^= 2;
                case 'i': cur ^= 4;
                case 'o': cur ^= 8;
                case 'u': cur ^= 16;
                default:break;
            }
            if(re[cur] == INT_MAX)re[cur] = i;
            else ans = max(ans, i-re[cur]);
        }
        return ans;
    }
};

// int main(){
//     Solution s;
//     cout<<s.findTheLongestSubstring("eleetminicoworoep")<<endl;
// }
// @lc code=end

