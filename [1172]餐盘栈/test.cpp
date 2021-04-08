// #include "1172.餐盘栈_2.cpp"
#include <iostream>
using namespace std;

// 1.可以直接引用其他cpp文件来使用其他文件的类，不需要特别表明命名空间
// 2.其他cpp头文件引用过、声明过的东西，不需要重复引用声明
// 3.#include <iostream>重复引用也没有报错..emm不理解
#include <set>
int main(){
    // test2
    set<int> a;
    set<int>::iterator it = a.begin();
    cout<<a.size()<<endl;
    a.insert(5);
    a.insert(3);
    a.insert(1);
    // set只能用迭代器获取元素
    
    cout<<*it<<endl;
    a.erase(*it); // 
    a.erase(1);a.erase(1);a.erase(1);// erase不存在东西好像也不会报错啊...
    it = a.begin();
    cout<<*it<<endl;


    // test1
    // DinnerPlates p(2);
    // p.push(1);p.push(2);p.push(3);p.push(4);p.push(5);
    // cout<<p.popAtStack(0)<<", ";
    // p.push(20);p.push(21);
    // cout<<p.popAtStack(0)<<", "<<p.popAtStack(2)<<", ";
    // cout<<p.pop()<<", "<<p.pop()<<", "<<p.pop()<<", "<<p.pop()<<", "<<p.pop()<<endl;
    return 0;
}