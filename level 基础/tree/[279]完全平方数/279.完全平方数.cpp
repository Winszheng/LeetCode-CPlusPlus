/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
// perfect squares 完全平方数——数学问题啊
// 任意正整数n，一定能表达成一个完全平方数——因为1是个完全平方数
// 搞半天还是个层序遍历，不过不是对树，而是对图，因为是一层一层写下去的，所以首先遇到的0，一定是步长最短的
// 但也因为这样，会重复连很多不必要的节点
// 用一个set记录已经加入了的节点，避免重复操作
// 虽然觉得有点奇怪，但是也是可以理解
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> tree;
        tree.push(make_pair(n, 0));
        set<int> visited;
        while(!tree.empty()){
            int num = tree.front().first;
            int d = tree.front().second;
            tree.pop();
            if(num == 0)return d;
            for(int i=1;num-i*i>=0;i++){    // 因为是图的关系，会重复加入很多节点以至于超时，要避免
                if(visited.find(num-i*i)!=visited.end())continue;
                tree.push(make_pair(num-i*i, d+1));
                visited.insert(num-i*i);
            }
        }
        return -1;
    }
};
// @lc code=end

