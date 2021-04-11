/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
// 要点是，多一个空间
// 请不要使用内置的队列库。
// 队列容量要比要求的多一个。这样才好操作。

class MyCircularQueue {
    int *arr;   // 队列用指针new数组表示，front、tail用下标表示即可
    int front, tail, cap;
public:
    MyCircularQueue(int k) {
        arr = new int[k+1];
        front = tail = 0;
        cap = k+1;
    }
    
    bool enQueue(int value) {   // 队尾插入元素
        if((tail+1)%cap == front)return false;
        arr[tail] = value;
        tail = (tail + 1) %cap;
        return true;
    }
    
    bool deQueue() {
        if(front == tail)return false;
        front = (front + 1) % cap;
        return true;
    }
    
    int Front() {
        if(front == tail)return -1;
        return arr[front];
    }
    
    int Rear() {
        if(front == tail)return -1;
        int index = (tail - 1 + cap) % cap;
        return arr[index];
    }
    
    bool isEmpty() {
        return front == tail;
    }
    
    bool isFull() {
        return (tail+1)%cap == front;
    }
};


// @lc code=end

