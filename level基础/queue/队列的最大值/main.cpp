#include <deque>
using namespace std;
// 题解：
// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/

// 一星：有重刷的必要
// 二星：有复习，与视情况重刷的必要
// 三星：刷的时候掌握的比较好，以后视情况处理

// 获取队列最大值
// 特点：
// 当一个元素入队时，之前的所有比他小的元素，都对答案没有影响
// 也就是说我要有一个辅助队列， 这个队列是递减的
// 由于队列头存最大值，主队列push值需要和辅助队列尾部比较
// 所以辅助队列应该是个双端队列

// 可以把主队列想象成一段一段的，主队列和辅助队列是多对一的关系
// —— 这样就留直观多了

#include <queue>
#include <deque>
using namespace std;
class MaxQueue {
    queue<int> a;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(d.empty())return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty() && value > d.back())d.pop_back();
        d.push_back(value);
        a.push(value);
    }
    
    int pop_front() {
        if(a.empty())return -1;
        int x = a.front();
        if(x == d.front())d.pop_front();
        a.pop();
        return x;
    }
};
