/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
// 相比排列问题，组合问题不考虑顺序
// 组合问题也是典型用回溯解决的

// 初始：
// Your runtime beats 5.11 % of cpp submissions
// Your memory usage beats 5.01 % of cpp submissions (217.2 MB)

// 把temp改成引用之后：
// 时空效率剧增，逻辑也变简单了
// Your runtime beats 75.42 % of cpp submissions
// Your memory usage beats 72.73 % of cpp submissions (9.6 MB)

// 剪枝之后：时空效率变慢了，因为虽然减少了递归但是增加了其他语句
class Solution {
    // index: from 1
    vector<vector<int>> re; // 是否把re定义在外面，对结果没影响
    void resolve(int n, int k, int start, vector<int>& temp){
        if(temp.size() == k){
            re.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
            temp.push_back(i);  // 这样省空间，节约了开空间销毁空间的时间
            resolve(n, k, i+1, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
       vector<int> temp;
       if(k>n || k<0 || n<0)return re;
       resolve(n, k, 1, temp);
       return re;
    }
};
// @lc code=end

