/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start

// 方法1：bfs+队列
// 多叉树结构
// 每次都把本层所有节点全遍历完，把后继放进去，一旦找到结果，就是最优解
// 空间效率不高，而且肯定有很多重复计算的问题
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int level = 1;
        while(1){
            for(int i = q.size(); i>0; i--){
                int temp = q.front();
                q.pop();
                int t = sqrt(temp);
                if(t*t == temp)return level;
                for(int j = t; j>0; j--){
                    q.push(temp-j*j);
                }
            }
            level++;
        }
        return -1;
    }
};

// @lc code=end

