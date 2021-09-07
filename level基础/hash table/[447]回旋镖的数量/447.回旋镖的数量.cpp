/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
// boomerangs 回旋镖      
// 从题意可以直接看出，i是枢纽
// 对每一个i，查其他所有点到i的距离，保存相同距离的点数
// 然后直接统计有多少个结果

// 对面每个点的结果单独列一个map保存会比较好
// map
// Your runtime beats 12.91 % of cpp submissions
// Your memory usage beats 12.48 % of cpp submissions (218.9 MB)

// unordered_map
// Your runtime beats 14.22 % of cpp submissions
// Your memory usage beats 14.23 % of cpp submissions (196.7 MB)
#include <vector>
#include <unordered_map>
using namespace std;

// 虽然开了n个map，但是做完一次循环就释放，所以空间复杂度实际上还是O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int re = 0;
        for(auto i : points){
            unordered_map<int, int> temp; // distance, count
            for(auto j : points){
                int d = (i[0]-j[0])*(i[0]-j[0]) + (i[1]-j[1])*(i[1]-j[1]);
                temp[d]++;
            }
            for(auto k : temp){
                re+=(k.second-1)*k.second;
            }
        }
        return re;
    }
};
// @lc code=end

