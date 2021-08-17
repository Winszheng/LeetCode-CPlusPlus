/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
// 分析：本质上相当于通过添加1、-1、0系数，使计算式结果为0时正数和最大(那么正数和最少是0)
// 在dp中，每根钢筋有3种操作：左、右、不用(对应上述三种系数)

// 参考：
// https://leetcode-cn.com/problems/tallest-billboard/solution/yi-quan-ji-ben-mei-shuo-ming-bai-de-zhe-pian-kan-l/
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp; dp[0] = 0;
        for(int n : rods){  // 对每根钢筋做循环
            unordered_map<int, int> temp(dp);   // 拷贝构造，为了不被新数据影响，导致循环有问题
            for(auto m :temp){  // 对已有的结果组合做循环
                int sum = m.first, positive = m.second;
                // + 要么dp[sum+n]已经存在过，要么不存在，需要根据当前数据自行生成
                dp[sum+n] = max(dp[sum+n], positive + n);
                // -
                dp[sum-n] = max(dp[sum-n], positive);

            }

        }
        return dp[0];
    }
};
// @lc code=end

// int main(){
//     map<int, int> re;
//     cout<<re[1]<<re[0]<<endl;
// }

