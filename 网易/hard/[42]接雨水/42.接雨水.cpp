/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// max_element: 获取指向可迭代对象最大值的迭代器，处理之后可以获取下标(妙啊)！

// 思路：
// 0.基本上可以把数组理解为“山峰”(貌似算寻峰问题的变种？)
// 最左置为初始标杆，只要比标杆小就计算雨水，比标杆大就赋值标杆，直到遇到最大值
// 同理，从右也来一遍
// 累计值即为雨水量
// 代码简单也没坑，主要是思路

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3)return 0;
        int re = 0;
        int m = max_element(height.begin(), height.end()) - height.begin();
        int f = height[0];
        for(int i=1; i<m; i++){
            if(height[i] < f){
                re +=f-height[i];
            }else{
                f = height[i];
            }
        }
        f = height[n-1];
        for(int i=n-2;i>m;i--){
            if(height[i] < f){
                re += f-height[i];
            }else{
                f = height[i];
            }
        }
        return re;
    }
};
// @lc code=end

// int main(){
//     vector<int> temp{0,1,0,2,1,0,1,3,2,1,2,1};
//     int m = max_element(temp.begin(), temp.end()) - temp.begin();
//     cout<<m<<endl;
// }