#include <iostream>
#include <stack>
using namespace std;
// 栈排序
// 栈空的时候pop不会报错，但是却可能影响其他的操作，让其他操作报错
// 蛇精病啊！
class SortedStack {
    stack<int> a, b;

   public:
    SortedStack() {}

    void push(int val) {
        while (!a.empty() && a.top() < val) {
            b.push(a.top());
            a.pop();
        }
        a.push(val);
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
    }  // O(n)

    void pop() { 
        if(a.empty())return;
        a.pop(); 
    }

    int peek() { return a.empty() ? -1 : a.top(); }

    bool isEmpty() { return a.empty(); }
};

int main() {
    SortedStack s;
    s.pop();
    s.pop();
    s.push(1);
    s.pop();
    s.isEmpty();
}