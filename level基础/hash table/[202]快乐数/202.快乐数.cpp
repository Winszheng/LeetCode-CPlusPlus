/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
// 其实就是检测一个数字是否有环
// 例如数字2
// 4-16-37-58-89-145-42-20-4
// 获得第二个4，说明开始进循环了，永远得不到1
// 其实就是求解这个操作有没有环
class Solution {
    int getnew(int n){
        int re = 0, r;
        while(n>0){
            r = n%10;
            n/=10;
            re += r*r;
        }
        return re;
    }
public:
    bool isHappy(int n) {
        map<int, int> record;
        while( n != 1){
            if(record[n] > 0)return false;
            record[n]++;
            n = getnew(n);
        }
        return true;
    }
};
// @lc code=end

