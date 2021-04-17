/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
// 质数：除了1和该数自身外，无法被其他自然数整除的数,质数大于1
// 这道题的管家在于容易超时
// 规避超时两件事：
// 1偶数只有2是质数——因为规避了质数，所以不仅case的数据规模可以少一半
//  而且查因数的时候也不用查偶数，即因数的数据规模也可以少一半
// 2.查因数用j*j<=i就行
// 但是这样还是有一个case过不了

// 优化：厄拉多塞筛法
// 虽然不知道为什么，总之不仅能过而且速度很快
// 原因大概是，这样的时间复杂度是O(n)，所以数据规模打的时候
#include <iostream>
using namespace std;
class Solution {
public:
    int countPrimes(int n){
        vector<bool> ans(n, true);
        int sum = 0;
        for(int i=2;i<n;i++){
            if(ans[i]){
                sum++;
                for(int j = i+i;j<n;j+=i)ans[j]=false;
            }
            
        }
        return sum;
    }
};

// int main(){
//     Solution s;
//     s.countPrimes(5000000);
// }
// @lc code=end

